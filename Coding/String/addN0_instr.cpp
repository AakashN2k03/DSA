#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int sum=0;
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			sum+=(s[i]-'0');
		}
	}
	cout<<"add num in string"<<sum;
}
