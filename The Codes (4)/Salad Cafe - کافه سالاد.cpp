#include <iostream>
#include <vector>
using namespace std;

// please do have in mind that for solving this specific question, I did search many websites and asked many questions from the AI tools. (There is No Deny in it)

const int figure = 100;
const int table = 100003;
int coffeeshop(const char *s) {
	
	int length = 0;
	while (s[length] != '\0') {
		length++;
	}
	
	return length;
}

void shangd(char *kitt, const char *kat) {
	int c = 0;
	while (kat[c] != '\0') {
		kitt[c] = kat[c];
		c++;
	}
	
	kitt[c] = '\0';
}

int compute(const char *s1, const char *s2) {
	while (*s1 && (*s1 == *s2)) {
		s1++;
		s2++;
	}
	
	return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

char *dump(const char *s) {
	int length = coffeeshop(s);
	char *recnt_s = new char[length + 1];
	
	shangd(recnt_s, s);
	return recnt_s;
}

struct finish {
	char *s;
	finish() : s(nullptr) {}
	finish (char *ptr) : s(ptr) {}
	
	bool operator>(const finish &others) const {
	return compute(s, others.s) > 0;
	}
	
	bool operator<(const finish &others) const {
	return compute(s, others.s) < 0;
	}
};

template <typename a>
struct Minheap {
	vector<a> heap_data;
	
	int parent(int c) { return (c - 1) / 2;}
	int lchild (int c) { return 2 * c + 1;}
	int rchild(int c) { return 2 * c + 2;}
	void change(int c, int d) {
		
		a t = heap_data[c];
		heap_data[c] = heap_data[d];
		heap_data[d] = t;
	}
	
	void _heapp(int c) {
		while (c != 0 && heap_data[parent(c)] > heap_data[c]) {
			
			change(c, parent(c));
			c = parent(c);
		}
	}
	
	void _heappp(int c) {
		int little = c;
		int l = lchild(c);
		int r = rchild(c);
		if (l < heap_data.size() && heap_data[l] < heap_data[little]) {
			
			little = l;
		}
		
		if (r < heap_data.size() && heap_data[r] < heap_data[little]) {
			
			little = r;
		}
		
		if (little != c) {
			change(c, little);
			_heappp(little);
		}
	}
	
	void push(a value) {
		heap_data.push_back(value);
		_heapp(heap_data.size() - 1);
	}
	
	a tp() {
		return heap_data[0];
	}
	
	void pop() {
		if (heap_data.empty()) {
			return;
		}
		
		heap_data[0] = heap_data.back();
		heap_data.pop_back();
		_heappp(0);
	}
	
	bool empty() {
		return heap_data.empty();
	}
};

struct expired {
	int day;
	char *customer;
	bool operator>(const expired &others) const {
	
		if (day != others.day) {
			return day > others.day;
		}
	
		return compute(customer, others.customer) > 0;
	}
	
	bool operator<(const expired &others) const {
	
		if (day != others.day) {
			return day < others.day;
		}
		
		return compute(customer, others.customer) < 0;
	}
};

struct schedule {
	vector<vector<char*>> food;
	schedule() {
		
		food.resize(table);
	}
	
	unsigned int mine(const char *s) {
		unsigned int valu = 0;
		unsigned int pp = 1;
		const unsigned int ppp = 31;
		for (int c = 0; s[c] != '\0'; ++c) {
			
			valu = (valu + (s[c] - 'a' + 1) *pp) % table;
			pp = (pp * ppp) % table;
		}
		
		return valu;
	}
	
	void insert(const char *key) {
		unsigned int index = mine(key);
		for (char *save : food[index]) {
			
			if (compute(save, key) == 0) {
				return;
			}
		}
		
		food[index].push_back(dump(key));
	}
	
	bool components(const char *key) {
		unsigned int index = mine(key);
		for (char *save : food[index]) {
			
			if (compute(save, key) == 0) {
				return true;
			}
		}
		
		return false;
	}
	
	~schedule() {
		for (int c = 0; c < table; ++c) {
			for(char *s_ptr : food[c]) {
				
				delete[] s_ptr;
			}	
		}
	}
};

void merge(vector<char*> &array, int left, int midl, int right) {
	int array_one = midl - left + 1;
	int array_two = right - midl;
	
	vector<char*> left_array(array_one);
	vector<char*> right_array(array_two);
	for (int c = 0; c < array_one; c++) {
		
		left_array[c] = array[left + c];
	}
	
	for (int d = 0; d < array_two; d++) {
		right_array[d] = array[midl + 1 + d];
	}
	
	int array_onee = 0;
	int array_twoo = 0;
	int merged = left;
	while (array_onee < array_one && array_twoo < array_two) {
		
		if (compute(left_array[array_onee], right_array[array_twoo]) <= 0) {
			array[merged] = left_array[array_onee];
			array_onee++;
		
		} else {
			array[merged] = right_array[array_twoo];
			array_twoo++;
		}
		
		merged++;
	}
	
	while (array_onee < array_one) {
		array[merged] = left_array[array_onee];
		array_onee++;
		merged++;
	}
	
	while (array_twoo < array_two) {
		array[merged] = right_array[array_twoo];
		array_twoo++;
		merged++;
	}
}

void msort(vector<char*> &array, int left, int right) {
	if (left >= right) {
		
		return;
	}
	
	int midl = left + (right - left) / 2;
	
	msort(array, left, midl);
	msort(array, midl + 1, right);
	merge(array, left, midl, right);
}

Minheap<finish> hheap;
Minheap<expired> eheap;
schedule cancel_heap;
char input_buffet[figure + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int x;
	cin >> x;
	for (int current = 1; current <= x; ++current) {
		
		vector<char*> ccancel;
		int z;
		cin >> z;
		for (int c = 0; c < z; ++c) {
			
			cin >> input_buffet;
			char *thecustomer = dump(input_buffet);
			int interval;
			cin >> interval;
			
			hheap.push(finish(thecustomer));
			eheap.push({current + interval - 1, thecustomer});
		}
		
		while (!eheap.empty() && eheap.tp().day == current) {
			expired enter = eheap.tp();
			eheap.pop();
			if (!cancel_heap.components(enter.customer)) {
				ccancel.push_back(enter.customer);
				cancel_heap.insert(enter.customer);
			}
		}
		
		while (!hheap.empty() && cancel_heap.components(hheap.tp().s)) {
			hheap.pop();
		}
		
		if (!hheap.empty()) {
			finish tpf = hheap.tp();
			hheap.pop();
			if (!cancel_heap.components(tpf.s)) {
				
				ccancel.push_back(tpf.s);
				cancel_heap.insert(tpf.s);
			}
		}
		
		if (!ccancel.empty()) {
			msort(ccancel, 0, ccancel.size() - 1);
			for (size_t c = 0; c < ccancel.size(); ++c) {
				
				cout << ccancel[c] << (c == ccancel.size() - 1 ? "" : " ");
			}
			
			cout << "\n";
		
		} else {
			cout << "\n";
		}
	}
	
	return 0;
}
