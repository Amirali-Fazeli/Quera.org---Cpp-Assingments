#include <iostream>
using namespace std;

struct node {
	
	int value;
	node *next;
	node (int valu) : value(valu), next(nullptr) {}
	
};

int count_N(node *first) {
	int count = 0;
	
	node *current = first;
	while (current != nullptr) {
		count++;
		current = current -> next;
	}
	
	return count;
}

void sorting(node *first) {
	if (first == nullptr) return;
	bool instead;
	
	node *current;
	node *last = nullptr;
	do { 
		
		instead = false;
		current = first;
		while (current -> next != last) {
			
			if (current -> value > current -> next -> value) {
				
				int t = current -> value;
				current -> value = current -> next -> value;
				current -> next -> value = t;
				instead = true;
			}
			
			current = current -> next;
		}
		
		last = current;
	
	} while (instead);
	
}

double median (node *first) {
	int count = count_N (first);
	sorting (first);
	node *current = first;
	
	for (int c = 0; c < count / 2 - (count % 2 == 0 ? 1 : 0); c++) {
		current = current -> next;
	}
	
	if (count % 2 == 0) {
		return (current -> value + current -> next -> value) / 2.0;
	
	} else {
		return current -> value;
	}
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
	
	cout << median (first) << endl;
	return 0;
}
