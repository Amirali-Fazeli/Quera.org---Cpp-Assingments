#include <iostream>
using namespace std;

int main()
{
	int m, n, a, f = 0;
	cin >> n >> m;
	
	for(int i = -10; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		
		{
			a = ((i + j) * (i + j) * (i + j)) / (j * j);
			f = f + a;
		}
	}
	
	cout << f << endl;
}

