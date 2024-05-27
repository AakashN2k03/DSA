#include<iostream>
using namespace std;
int main()
{
	int n,sq,rem1,rem2;
	cout<<"enter the no";
	cin>>n;
	sq=n*n;
	rem1=sq%10;
	rem2=n%10;
	if(rem1==rem2)
	{
		cout<<"AUTOMORPHIC NUMBER"<<sq;
	}
	else{
		cout<<"NOT A AUTOMORPHIC NO"<<sq;
	}
	
}
