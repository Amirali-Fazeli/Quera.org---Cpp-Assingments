#include <iostream>
using namespace std;

struct node {
	char value;
	node *next;
	node(char valu) : value(valu), next (nullptr) {}	
};

bool Palindrome(node *first, int length) {
	char *val = new char[length];
	int figure = 0;
	
	node *current = first;
	while (current != nullptr) {
		val[figure++] = current -> value;
		current = current -> next;
	}
	
	for (int c = 0; c < length / 2; c++) {
		
		if (val[c] != val[length - c - 1]) {
			delete[] val;
			return false;
		}
	}
	
	delete[] val;
	return true;
}

int main() {
	int length;
	cin >> length;
	node *first = nullptr;
	node *last = nullptr;
	
	for (int c = 0; c < length; c++) {
		char value;
		cin >> value;
		node *recntnode = new node(value);
		
		if (first == nullptr) {
			first = recntnode;
			last = first;
		
		} else {
			last -> next = recntnode;
			last = recntnode;
		}
	}
	
	if (Palindrome(first, length)) {
		cout << "YES" << endl;
	
	} else {
		cout << "NO" << endl;
	}
	
	return 0;
}
