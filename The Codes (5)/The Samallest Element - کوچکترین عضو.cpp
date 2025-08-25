#include <iostream>
#include <vector>
using namespace std;

struct node {
	int value;
	
	node *left;
	node *right;
	node (int valu) : value(valu), left(nullptr), right(nullptr) {}
};

node *ins(node *tree, int valu) {
	
	if (tree == nullptr) {
		return new node(valu);
	}
	
	if (valu < tree -> value) {
		tree -> left = ins(tree -> left, valu);
	
	} else if (valu > tree -> value) {
		tree -> right = ins(tree -> right, valu);
	}
	
	return tree;
}

int search(node *tree) {
	
	if (tree == nullptr) {
		return 0;
	}
	
	node *currently = tree;
	while (currently -> left != nullptr) {
		
		currently = currently -> left;
	}
	
	return currently -> value;
}

void binary(node *tree) {
	
	if (tree == nullptr) {
		return;
	}
	
	binary(tree -> left);
	binary(tree -> right);
	delete tree;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int x;
	cin >> x;
	node *tree = nullptr;
	
	for (int c = 0; c < x; ++c) {
		
		int figure;
		cin >> figure;
		tree = ins(tree, figure);
	}
	
	int little = search(tree);
	
	cout << little << endl;
	binary(tree);
	
	return 0;
}

