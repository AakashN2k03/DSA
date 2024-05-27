#include<iostream>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]>='A'&& s[i]<='Z')
		{
			s[i]=s[i]+32;	
		}
		
		else{
		     s[i]=s[i]-32;		
		}
				
	}
	
	cout<<"toggled\n";
    cout<<s;
	
}
