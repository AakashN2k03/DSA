#include<iostream>
using namespace std;
int main()
{
	int n,rem,sum,temp;
	sum=0;
	cout<<"enter the number";
	cin>>n;
	temp=n;
	while(n!=0){
		rem=n%10;
		sum+=rem;
		n=n/10;
	}
	cout<<"sum="<<sum<<endl;
	if (temp%sum==0)
	{ cout<<"yes,harshad no"<<temp;
	}
	else{
		cout<<"not a harshad number";
	}
}
