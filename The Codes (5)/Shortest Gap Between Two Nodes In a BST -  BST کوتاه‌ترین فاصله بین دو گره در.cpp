#include <iostream>
#include <vector>
using namespace std;

struct node {
	int value;
	node *left;
	node *right;
	node (int valu) : value(valu), left(nullptr), right(nullptr) {}
};

node *ins(node *knot, int value) {
	if (!knot) return new node(value);
	
	if (value < knot -> value)
		
		knot -> left = ins(knot -> left, value);
	else
		knot -> right = ins(knot -> right, value);
	
	return knot;
}

bool isthere(node *knot, int val) {
	while (knot) {
		
		if (knot -> value == val) return true;
		
		if (val < knot -> value)
			
			knot = knot -> left;
		else
			knot = knot -> right;
	}
	
	return false;
}

node *find(node *knot, int a, int b) {
	if (!knot) return nullptr;
	
	if (knot -> value > a && knot -> value > b)
		return find(knot -> left, a, b);
	
	if (knot -> value < a && knot -> value < b)
		return find(knot -> right, a, b);
	
	return knot;
}

int further(node *knot, int val) {
	int deep = 0;
	while (knot && knot -> value != val) {
		
		if (val < knot -> value)
			
			knot = knot -> left;
		else
			knot = knot -> right;
		
		deep++;
	}
	
	return deep;
}

int main() {
	int x, a, b;
	cin >> x >> a >> b;
	vector<int> figures(x);
	for (int c = 0; c < x; ++c) cin >> figures[c];
	
	node *knot = nullptr;
	for (int c = 0; c < x; ++c)
	
		knot = ins(knot, figures[c]);
	node *Node = find(knot, a, b);
	int much = further(Node, a);
	int many = further(Node, b);
	
	cout << (much + many) << endl;
	
	return 0;
}
