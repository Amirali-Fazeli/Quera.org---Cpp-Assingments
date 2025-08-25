#include <iostream>
#include <vector>

using namespace std;

const int governor = 300000;
const int prize = 22;
const long long full = 1e18;

vector<int> subgov[governor + 1];
vector<vector<long long>> province;
vector<int> route[governor + 1];
vector<int> road;
int current;

void Tree(int a, int b) {
	road[a] = b;
	for (size_t c = 0; c < subgov[a].size(); ++c) {
		
		int z = subgov[a][c];
		if (z == b) continue;
		
		route[a].push_back(z);
		Tree(z, a);
	}
}

void coin(int a) {
	for (size_t c = 0; c < route[a].size(); ++c) {
		
		int z = route[a][c];
		coin(z);
	}
	
	for (int d = 1; d <= prize; ++d) {
		province[d][a] = d;
	}
	
	for (size_t c = 0; c < route[a].size(); ++c) {
		
		int z = route[a][c];
		long long deputy = full;
		long long secretary = full;
		
		int ccoin = -1;
		for (int k = 1; k <= prize; ++k) {
			
			if (province[k][z] < deputy) {
				
				secretary = deputy;
				deputy = province[k][z];
				ccoin = k;
			
			} else if (province[k][z] < secretary) {
				secretary = province[k][z];
			}
		}
		
		if (deputy == full) {
			for (int d = 1; d <= prize; ++d) {
				
				province[d][a] = full;
			}
			
			return;
		}
		
		for (int d = 1; d <= prize; ++d) {
			
			if (province[d][a] == full) continue;
			
			if(d != ccoin) {
				
				province[d][a] += deputy;
			
			} else {
				province[d][a] += secretary;
			}
			
			if (province[d][a] >= full / 2) province[d][a] = full;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		
		cin >> current;
		for (int c = 1; c <= current; ++c) {
			
			subgov[c].clear();
			route[c].clear();
		}
		
		if (current == 1) {
			cout << 1 << "\n";
			continue;
		}
		
		for (int c = 0; c < current - 1; ++c) {
			
			int a, z;
			cin >> a >> z;
			subgov[a].push_back(z);
			subgov[z].push_back(a);
		}
		
		province.assign(prize + 1, vector<long long>(current + 1, full));
		road.assign(current + 1, 0);
		
		Tree(1, 0);
		coin(1);
		
		long long outcome = full;
		for (int d = 1; d <= prize; ++d) {
			
			outcome = (province[d][1] < outcome ? province[d][1] : outcome);
		}
		
		cout << outcome << "\n";
	}
	
	return 0;
}
