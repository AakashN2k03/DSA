#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n,sq;
	cout<<"enter the number";
	cin>>n;
	sq=sqrt(n);
	if((sq*sq)==n)
	{
		cout<<"yes,perfect sq"<<sq;
	}
	else
	{
		cout<<"no, perfect sq";
	}
}

/*#include<iostream>
using namespace std;
int main()
{
	int i,n;
	cin>>n;
	for(i=1;i<n;i++)
	{
		if(n%i==0)
		{
			if(i*i==n)
			{
				cout<<"perfect sq";
				break;
			}
		}
	}
}*/
