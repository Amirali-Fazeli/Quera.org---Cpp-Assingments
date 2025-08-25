#include <iostream>
using namespace std;

int main()
{
	int l;
	cin >> l;
	
	for(int i = 1; i <= l; i++)
	{
		for(int j = 1; j <= l; j++)
		
		{
			cout << i * j << " ";
		}
		
		cout << endl;
	}
	
	return 0;
}
