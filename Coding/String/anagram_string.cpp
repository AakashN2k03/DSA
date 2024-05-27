#include <iostream>
using namespace std;

int main() {
    string s,ss;
    int n,n1,j,i,count,uncount;
    cout << "Enter the string: ";
    getline(cin, s);
     cout << "Enter the string: ";
    getline(cin, ss);
    
    n=s.length();
    n1=s.length();  
    
    if(n==n1)
    {  for(i=0;i<n;i++)
        {  count=0;
        	for(j=0;j<n1;j++)
        	{
        		if(s[i]==ss[j])
        		{
        			count=1;
        			break;
				}
			}
			if(count==0)
		{
			uncount=1;
			break;
		}
	}
		if(uncount==1)
		{
			cout<<"it is not anagram";
		}
		else{
			cout<<"it is anagram";
		}
    	
	}
	else{
		cout<<"cannot be anagramed";
	}
    
    return 0;
}

