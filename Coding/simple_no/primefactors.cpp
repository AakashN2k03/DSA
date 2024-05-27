#include<iostream>
using namespace std;
int main()
{
	int number,count;
	cout<<"ENTER THE NO TO FIND FACTORS";
	cin>>number;
	for(int i=1;i<=number;i++)
	{
		if(number%i==0)
		{
			count=0;
			
			for(int j=1;j<=i;j++)
			{
				if(i%j==0){
					count=count+1;
				}
				
				}
	    	if(count==2){
			 cout<<i;
		}	
		}
	}
	
}
