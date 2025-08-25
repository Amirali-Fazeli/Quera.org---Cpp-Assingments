#include <iostream>
using namespace std;

struct queue {
	char *array;
	int forward;
	int backward;
	
	int space;
	int len;
	
	queue(int spac) {
		space = spac;
		array = new char[space];
		
		forward = 0;
		backward = -1;
		len = 0;
	}
	
	~queue() {
		delete[] array;
	}
	
	void enqueue(char value) {
		if (len == space) return;
		
		backward = (backward + 1) % space;
		array[backward] = value;
		len++;
	}
	
	char dequeue() {
		if (len == 0) return '#';
		
		char value = array[forward];
		forward = (forward + 1) % space;
		len--;
		return value;
	}
	
	char front() {
		if (len == 0) return '#';
		
		return array[forward];
	}
	
	int size() {
		return len;
	}
	
	bool clear() {
		return len == 0;
	}
};

string Nrepeat(string &put) {
	queue que(put.length());
	int count[26] = {0};
	
	string out;
	for (int c = 0; c < put.length(); c++) {
		
		char current = put[c];
		count[current - 'a']++;
		que.enqueue(current);
		while (!que.clear() && count[que.front() - 'a'] > 1) {
			
			que.dequeue();
		}
		
		if (que.clear()) {
			out += '#';
		
		} else {
			out += que.front();
		}
	}
	
	return out;
}

int main() {
	string put;
	cin >> put;
	
	string out = Nrepeat(put);
	cout << out << endl;
	
	return 0;
}
