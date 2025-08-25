#include <iostream>
using namespace std;

int main()
{
	int n;
	char l;
	string s;
	
	bool b = 0;
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		cin >> s;
		if(s == "CAPS")
		
		{
		  b = !b;	
		}
		
		else
		{
			if(b == 1)
			{
				l = (char)(s[0]-('a'-'A'));
				cout << l;
			}
			
			else
			{
				cout << s;
			}
		}
	}
}
