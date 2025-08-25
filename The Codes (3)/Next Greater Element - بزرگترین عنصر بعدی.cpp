#include <iostream>
using namespace std;

struct stack {
	
	int *array;
	int tp;
	int space;
	stack (int size) {
		
		space = size;
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


void find(int *array, int x, int *outcome) {
	stack stac(x);
	for (int c = x - 1; c >= 0; c--) {
		
		while (!stac.clear() && stac.climax() <= array[c]) {
			stac.forwar();
		}
		
		if (stac.clear()) {
			outcome[c] = -1;
			
		} else {
			outcome[c] = stac.climax();
		}
		
		stac.forward(array[c]);
	}
}

int main() {
	int x;
	cin >> x;
	int *array = new int[x];
	
	int *outcome = new int[x];
	for (int c = 0; c < x; c++) {
		
		cin >> array[c];
	}
	
	find(array, x, outcome);
	for (int c = 0; c < x; c++) {
		
		cout << outcome[c] << " ";
	}
	
	cout << endl;
	delete[] array;
	delete[] outcome;
	
	return 0;
	
}
