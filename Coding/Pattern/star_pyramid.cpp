#include<iostream>
using namespace std;
int main()
{
	int n,i,j,k;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(int k=1;k<=n-i;k++)
		{
			cout<<"  ";
		}
		for(j=1;j<=2*i-1;j++)
		{
			cout<<"* ";
		}
		cout<<"\n";
		
	}
}
