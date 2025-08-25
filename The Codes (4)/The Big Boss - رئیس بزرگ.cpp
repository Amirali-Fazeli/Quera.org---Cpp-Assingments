#include <iostream>
using namespace std;

struct node {
	int a;
	node *next;
	node (int a) {
		
		this -> a = a;
		next = nullptr;
	}
};

struct lst {
	node *first;
	lst () {
		
		first = nullptr;
	}
	
	void in(int a) {
		node *recntnode = new node(a);
		recntnode -> next = first;
		first = recntnode;
	}
};

struct company {
	
	lst *labor;
	int labour;
	company(int x) {
		
		labour = x;
		labor = new lst[x + 1];
	}
	
	~company() {
		delete[] labor;
	}
	
	void sub(int master, int worker) {
		labor[master].in(worker);
	}
	
	int cost() {
		return boss(1, 1);
	}
	
private:
	
	int boss(int manager, int prof) {
		int value = prof;
		
		node *currently = labor[manager].first;
		while (currently) {
			
			value += boss(currently -> a, prof + 1);
			currently = currently -> next;
		}
		
		return value;
	}
};

int main() {
	int x;
	cin >> x;
	company co(x);
	
	for (int c = 2; c <= x; c++) {
		int master;
		cin >> master;
		
		co.sub(master, c);
	}
	
	cout << co.cost() << endl;
	
	return 0;
}
