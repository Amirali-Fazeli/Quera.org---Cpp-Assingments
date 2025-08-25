#include <iostream>
#include <vector>
using namespace std;

void merge(vector<vector<int>>& interv, int left, int mid, int right) {
    int a = mid - left + 1;
    int b = right - mid;
    vector<vector<int>> L(a, vector<int>(2)), R(b, vector<int>(2));
    
    for (int c = 0; c < a; c++) {
        L[c][0] = interv[left + c][0];
        L[c][1] = interv[left + c][1];
    }
    
    for (int d = 0; d < b; d++) {
        R[d][0] = interv[mid + 1 + d][0];
        R[d][1] = interv[mid + 1 + d][1];
    }
    
    int c = 0, d = 0, e = left;
    while (c < a && d < b) {
        if (L[c][1] < R[d][1] || (L[c][1] == R[d][1] && L[c][0] < R[d][0])) {
            interv[e][0] = L[c][0];
            interv[e][1] = L[c][1];
            c++;
        } else {
            
			interv[e][0] = R[d][0];
            interv[e][1] = R[d][1];
            d++;
        }
        e++;
    }
    
    while (c < a) {
        interv[e][0] = L[c][0];
        interv[e][1] = L[c][1];
        c++;
        e++;
    }
    
    while (d < b) {
        interv[e][0] = R[d][0];
        interv[e][1] = R[d][1];
        d++;
        e++;
    }
}

void mergeSort(vector<vector<int>>& interv, int x) {
    for (int current = 1; current <= x - 1; current *= 2) {
        for (int left = 0; left < x - 1; left += 2 * current) {
            
			int mid = (left + current - 1 < x - 1) ? left + current - 1 : x - 1;
            int right = (left + 2 * current - 1 < x - 1) ? left + 2 * current - 1 : x - 1;
            merge(interv, left, mid, right);
        }
    }
}

int Chain(vector<vector<int>>& interv) {
    mergeSort(interv, interv.size());
    int thecount = 0;
    int lastfig = -1000000;
    for (int c = 0; c < interv.size(); c++) {
        
		if (interv[c][0] >= lastfig) {
            thecount++;
            lastfig = interv[c][1];
        }
    }
    
	return thecount;
}

int main() {
    int y;
    cin >> y;
    vector<vector<int>> interv(y, vector<int>(2));
    
	for (int c = 0; c < y; c++) {
        cin >> interv[c][0] >> interv[c][1];
    }
    
    cout << Chain(interv) << endl;
    return 0;
}
