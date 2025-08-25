#include <iostream>
using namespace std;

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

void reverse(queue &que, int a) {
	int *stack = new int[a];
	int tp = -1;
	for (int c = 0; c < a; c++) {
		
		stack[++tp] = que.dequeue();
	}
	
	while (tp >= 0) {
		que.enqueue(stack[tp--]);
	}
	
	int others = que.size() - a;
	for (int c = 0; c < others; c++) {
		
		que.enqueue(que.dequeue());
	}
	
	delete[] stack;
}

int main() {
	int x, a;
	cin >> x >> a;
	
	queue que(x);
	for (int c = 0; c < x; c++) {
		
		int value;
		cin >> value;
		que.enqueue(value);
	}
	
	reverse(que, a);
	while (que.size() > 0) {
		
		cout << que.dequeue() << " ";
	}
	
	cout << endl;
	return 0;
}
