#include<iostream>
using namespace std;
int main(){
	int n,sum,copy;
	sum=0;
	cout<<"enter the no";
	cin>>n;
	copy=n;
	for(int i=1;i<n;i++)
	{  
		if(n%i==0)
		{
			sum=sum+i;
		}
	}
	if(sum==copy)
	{
		cout<<"perfect number"<<sum;
	}
	else{
		cout<<"not a perfect no"<<sum;
	}
}
