#include <iostream>
using namespace std;

struct dequeue {
	
	int *array;
	int forward;
	int backward;
	
	int space;
	int length;
	
	dequeue(int spac) {
		space = spac;
		array = new int[space];
		
		forward = -1;
		backward = -1;
		length = 0;
	}
	
	~dequeue() {
		delete[] array;
	}
	
	bool pf(int value) {
		if (length == space) return false;
		
		if (forward == -1) {
			forward = 0;
			backward = 0;
		
		} else {
			forward = (forward - 1 + space) % space;
		
		}
		
		array[forward] = value;
		length++;
		return true;
	}
	
	bool pb(int value) {
		if (length == space) return false;
		
		if (backward == -1) {
			forward = 0;
			backward = 0;
			
		} else {
			backward = (backward + 1) % space;
		}
		
		array[backward] = value;
		length++;
		return true;
	}
	
	int front() {
		if (length == 0) return -1;
		
		return array[forward];
	}
	
	int back() {
		if (length == 0) return -1;
		
		return array[backward];
	}
};

void deq(int x) {
	dequeue dequeu(x);
	string que;
	
	int value;
	int fore = -1;
	int backk = -1;
	
	bool fque = false;
	bool rque = false;
	
	for (int c = 0; c < x; c++) {
		cin >> que;
		
		if (que == "pf") {
			
			cin >> value;
			if (!dequeu.pf(value)) {
				
				continue;
			}
		
		} else if (que == "pb") {
			
			cin >> value;
			if (!dequeu.pb(value)) {
				
				continue;
			}
		
		} else if (que == "f") {
			
			fore = dequeu.front();
			fque = true;
		
		} else if (que == "pp_b") {
			
			backk = dequeu.back();
		}
	}
	
	if (fque && fore != -1) {
		cout << fore << endl;
		rque = true;
	
	} else if (backk != -1) {
		cout << backk << endl;
		rque = true;
	
	} 
	
	if (!rque) {
		cout << -1 << endl;
	}
}

int main() {
	int x;
	cin >> x;
	
	deq(x);
	return 0;
	
}
