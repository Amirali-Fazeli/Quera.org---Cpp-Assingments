#include <iostream>
using namespace std;

int c[200];
int main()
{
	
	int a, b, n, x=0;
	cin >> a >> b;
	
	for(int i = a + 1; i < b; i++)
	{
		n = 0;
        for(int j = 2; j * j <= i; j++)
        
		{
            if(i % j == 0)
			
			{
				n = 1;
			}	
		}
         
		 if(n == 0)
         
		 {
            c[x] = i;
            x++;
		 }
	}
	
	for(int i = 0; i < x; i++)
	
	{
	    cout << c[i];	 
	    
		if (i != x - 1)
	    
		{
	      	cout << ",";
		}
	}
    
	return 0;
}
