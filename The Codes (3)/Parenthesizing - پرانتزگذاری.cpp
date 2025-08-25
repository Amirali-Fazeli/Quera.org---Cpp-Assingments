#include <iostream>
using namespace std;

struct stack {
	
	int * array;
	int tp;
	int space;
	
	stack(int size) {
		
		space = size;
		array = new int[space];
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

int find(char p[], int length) {
	
	int maxl = 0;
	stack stac(length);
	stac.forward(-1);
	
	for (int c = 0; c < length; c++) {
		
		if(p[c] == '(') {
			stac.forward(c);
		
		} else if (p[c] == ')') {
			
			stac.forwar();
			if (stac.clear()) {
				
				stac.forward(c);

			} else {
				
				maxl = max(maxl, c - stac.climax());
			}
		}
	}
	
	return maxl;
}

int main() {
	
	char input[1000];
	cin >> input;
	int length = 0;
	
	while (input[length] != '\0') length++;
	cout << find(input, length) << endl;
	return 0;
}
