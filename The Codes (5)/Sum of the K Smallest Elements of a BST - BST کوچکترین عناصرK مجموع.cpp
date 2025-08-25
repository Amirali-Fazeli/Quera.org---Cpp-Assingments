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

void summation(node *knot, int &a, int &all) {
	if (!knot || a == 0) return;
	
	summation(knot -> left, a, all);
	if (a > 0) {
		
		all += knot -> value;
		a--;
	}
	
	summation(knot -> right, a, all);
}

int main() {
	int x, a;
	cin >> x >> a;
	vector<int> figures(x);
	for (int c = 0; c < x; ++c) cin >> figures[c];
	
	node *knot = nullptr;
	for (int c = 0; c < x; ++c) knot = ins(knot, figures[c]);
	
	int all = 0;
	summation(knot, a, all);
	cout << all << endl;
	
	return 0;
}
