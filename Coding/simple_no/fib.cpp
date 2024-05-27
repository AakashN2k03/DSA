#include<iostream>
using namespace std;
int main()
{
	int n,a,b,next;
	a=0,b=1;
	cout<<"enter the limit";
	cin>>n;
	cout<<a<<"\n"<<b<<"\n";
	for(int i=2;i<=n;i++)
	{
		next=a+b;
		a=b;
		b=next;
		cout<<next<<"\n";
	}
}
