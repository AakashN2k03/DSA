#include<iostream>
using namespace std;
int main()
{
	int n,rem,sum=0,temp;
	
	cout<<"enter the no";
	cin>>n;
	temp=n;
	while(n!=0)
	{
		rem=n%10;
		sum=(rem*rem*rem)+sum;
		n=n/10;
	}
	if(temp==sum)
		{
			cout<<"yes,it is armstrong"<<temp;
		}
		else{
			cout<<"not a armstrong\n"<<temp;
		}
}
