#include <iostream>
using namespace std;

struct stack {
	
	int *array;
	int tp;
	int space;
	stack (int length) {
		
		space = length;
		array = new int [space];
		tp = -1;
	}
	
	~stack() {
		delete[] array;
	}
	
	void forward(int value) {
		if (tp == space - 1) return;
		array[++tp] = value;
	}
	
	int forwar() {
		if (tp == -1) return -1;
		return array[tp--];
	}
	
	int climax() {
		if (tp == -1) return -1;
		return array[tp];
	}
	
	bool clear() {
		return tp == -1;
	}
};

struct queue {
	int *array;
	int forward;
	int backward;
	
	int space;
	int length;
	
	queue(int spac) {
		space = spac;
		array = new int[space];
		
		forward = 0;
		backward = -1;
		length = 0;
	}
	
	~queue() {
		delete[] array;
	}
	
	void enqueue(int value) {
		if (length == space) return;
		
		backward = (backward + 1) % space;
		array[backward] = value;
		length++;
		
		}
		
	int dequeue() {
		if (length == 0) return -1;
		
		int value = array[forward];
		forward = (forward + 1) % space;
		length--;
		return value;
	}
	
	int front() {
		if (length == 0) return -1;
		return array[forward];
	}
	
	int size() {
		return length;
	}
};

bool permutation(queue &putqueue, queue &outqueue, int len) {
	stack stac(len);
	while (putqueue.size() > 0) {
		
		int value = putqueue.dequeue();
		stac.forward(value);
		while (!stac.clear() && stac.climax() == outqueue.front()) {
			
			outqueue.dequeue();
			stac.forwar();
		}
	}
	
	return outqueue.size() == 0;
}

int main() {
	int len;
	cin >> len;
	
	queue putqueue(len);
	queue outqueue(len);
	for (int c = 0; c < len; c++) {
		
		int value;
		cin >> value;
		putqueue.enqueue(value);
	}
	
	for (int c = 0; c < len; c++) {
		
		int value;
		cin >> value;
		outqueue.enqueue(value);
	}
	
	if (permutation(putqueue, outqueue, len)) {
		cout << "YES" << endl;
	
	} else {
		cout << "NO" << endl;
	
	}
	
	return 0;
}	
