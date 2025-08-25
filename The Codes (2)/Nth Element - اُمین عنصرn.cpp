#include <iostream>
using namespace std;

struct node {
	int value;
	node *next;
	node(int valu) : value(valu), next(nullptr) {}
};

int N_th(node *first, int x, int length) {
	
	if (x > length) {
		x = length;
	}
	
	int figure = length - x;
	node *current = first;
	
	for (int c = 0; c < figure; c++) {
		current = current -> next;
	}
	
	return current -> value;
}

int main() {
	int length, x;
	cin >> length >> x;
	node *first = nullptr;
	node *last = nullptr;
	
	for (int c = 0; c < length; c++) {
		int value;
		cin >> value;
		node *recntnode = new node(value);
	
		if( first == nullptr) {
			first = recntnode;
			last = first;
	
		} else {
			last -> next = recntnode;
			last = recntnode;
		}	
	}
	
	cout << N_th(first, x, length) << endl;
	return 0;
}
