#include<iostream>
using namespace std;
int main()
{
	int n,temp,copy,sum;
	cout<<"enter the number";
	cin>>n;
	copy=n;
	sum=0;
    
	while(n!=0)
	{ int fact=1;
	  temp=n%10;
	   for(int i=1;i<=temp;i++)
	   {
	   	 fact=fact*i;
	   }
	   
	   sum=sum+fact;
	  
	   n=n/10;
	   
	  
	}
	if(copy==sum)
	{
		cout<<"it is strong number"<<sum;
	}
	else{
		cout<<"not a strong number";
	}
	
	
}
