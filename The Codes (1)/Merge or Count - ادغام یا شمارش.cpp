#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
	int a = mid - left + 1;
	int b = right - mid;
	vector<int> L(a), R(b);
	
	for (int c = 0; c < a; c++)
		L[c] = arr[left + c];
	for (int d = 0; d < b; d++)
		R[d] = arr[mid + 1 + d];
	
	int c = 0, d = 0, e = left;
	while (c < a && d < b) {
		if (L[c] <= R[d]) {
			arr[e] = L[c];
			c++;
		} else {
			arr[e] = R[d];
			d++;
		}
		e++;
	}
	
	while (c < a) {
		arr[e] = L[c];
		c++;
		e++;
	}
	
	while (d < b) {
		arr[e] = R[d];
		d++;
		e++;
	}
}

void mergeSort(vector<int>& arr, int x) {
	for (int current = 1; current < x; current *= 2) {
		for (int left = 0; left < x - 1; left += 2 * current) {
			int mid = min(left + current - 1, x - 1);
			int right = min(left + 2 * current - 1, x - 1);
			merge(arr, left, mid, right);
		}
	}
}

int main () {
	int f, g;
	cin >> f >> g;
	vector<int> arr(f);
	for (int c = 0; c < f; c++) {
		cin >> arr[c];
	}
	
	mergeSort(arr, f);
	for (int c = 0; c < f; c++) {
		cout << arr[c];
		if (c != f - 1) cout << " ";
	}
	
	cout << endl;
	return 0;
}
