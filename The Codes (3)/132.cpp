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

bool algorithm(int *array, int x) {
	
	if (x < 3) return false;
	stack stac(x);
	int two = -100000000;
	for (int c = x - 1; c >= 0; c--) {
		
		if(array[c] < two) {
			return true;
		}
		
		while (!stac.clear() && array[c] > stac.climax()) {
			two = stac.forwar();
		}
		
		stac.forward(array[c]);
	}
	
	return false;
}

int main() {
	int x;
	cin >> x;
	int *array = new int [x];
	for (int c = 0; c < x; c++) {
		
		cin >> array[c];
	}
	
	if (algorithm(array, x)) {
		cout << "YES" << endl;
	
	} else {
		cout << "NO" << endl;
	
	}
	
	delete[] array;
	return 0;
}
