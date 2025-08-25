#include <iostream>
using namespace std;

struct node {
	
	int value;
	node *next;
	node (int valu) : value(valu), next(nullptr) {}
};

void Deduplication(node *first) {
	node *current = first;
	
	while (current != nullptr) {
		node *forward = current;
		while (forward -> next != nullptr) {
			
			if (forward -> next -> value == current -> value) {
				
				node *duplicate = forward -> next;
				forward -> next = duplicate -> next;
				delete duplicate;
			
			} else {
				forward = forward -> next;
			}
		}
		
		current = current -> next;
	}
}

void finallist(node *first) {
	node *current = first;
	
	while (current != nullptr) {
		cout << current -> value << " ";
		current = current -> next;
	}
	
	cout << endl;
}

int main() {
	int x;
	cin >> x;
	node *first = nullptr;
	node *last = nullptr;
	
	for (int c = 0; c < x; c++) {
		int value;
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
	
	Deduplication(first);
	finallist(first);
	return 0;
}
