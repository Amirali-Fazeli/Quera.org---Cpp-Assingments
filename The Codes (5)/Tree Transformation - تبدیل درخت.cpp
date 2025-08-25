#include <iostream>
#include <vector>
using namespace std;

struct node {
	long long value;
	node *left;
	node *right;
	node (long long valu) : value(valu), left(nullptr), right(nullptr) {}
};

int main () {
	int a;
	cin >> a;
	long long Node = (1LL << a) - 1;
	vector <long long> array(Node);
	for (long long c = 0; c < Node; ++c) cin >> array[c];
	
	bool find = false;
	for (long long c = 0; c < Node; ++c) {
		
		if (array[c] == - 1) {
			
			find = true;
		
		} else if (find) {
			cout << "No" << endl;
			
			return 0;
		}
	}
	
	vector<node *>tree(Node, nullptr);
	for (long long c = 0; c < Node; ++c) {
		
		if (array[c] != -1) {
			
			tree[c] = new node(array[c]);
		}
	}
	
	for (long long c = 0; c < Node; ++c) {
		
		if (tree[c]) {
			
			long long leftt = 2 * c + 1;
			long long rightt = 2 * c + 2;
			if (leftt < Node) tree[c] -> left = tree[leftt];
			if (rightt < Node) tree[c] -> right = tree[rightt];
		}
	}
	
	if (Node == 0 || array[0] == -1) {
		
		cout << "Yes" << endl;
		return 0;
	}
	
	vector<node*> b;
	b.push_back(tree[0]);
	for (size_t c = 0; c < b.size(); ++c) {
		
		node *knot = b[c];
		if (knot -> left) {
			
			if (knot -> value < knot -> left -> value) {
				
				cout << "No" << endl;
				return 0;
			}
			
			b.push_back(knot -> left);
		}
		
		if (knot -> right) {
			
			if (knot -> value < knot -> right -> value) {
				
				cout << "No" << endl;
				return 0;
			}
			
			b.push_back(knot -> right);
		}
	}
	
	cout << "Yes" << endl;
	return 0;
}
