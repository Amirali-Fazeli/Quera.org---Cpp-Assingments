#include <iostream>
using namespace std;

const int all = 1001;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	char array[all];
	cin >> array;
	
	int x = 0;
	while(array[x] != '\0') {
		
		x++;
	}
	
	if (x == 0) {
		cout << "" << endl;
		return 0;
	}
	
	if (x == 1) {
		cout << array << endl;
		return 0;
	}
	
	int counting[26] = {0};
	for (int c = 0; c < x; ++c) {
		
		counting[array[c] - 'a']++;
	}
	
	char outcome[all];
	int length = 0;
	char end = '\0';
	
	char car = '\0';
	char repeat = 0;
	for (int c = 0; c < x; ++c) {
		
		if (car != '\0') {
			
			counting[car - 'a'] = repeat;
			car = '\0';
			repeat = 0;
		}
		
		char first = '\0';
		int frequency = 0;
		for (int d = 0; d < 26; ++d) {
			
			char currently = 'a' + d;
			if (counting[d] > 0 && currently != end) {
				
				if (counting[d] > frequency) {
					
					frequency = counting[d];
					first = currently;
				}
			}
		}
		
		if (first == '\0') {
			
			cout << "NotPossible" << endl;
			return 0;
		}
		
		outcome[length++] = first;
		counting[first - 'a']--;
		end = first;
		
		car = first;
		repeat = counting[first - 'a'];
		counting[first - 'a'] = 0;
	}
	
	outcome[length] = '\0';
	cout << outcome << endl;
	
	return 0;
}

