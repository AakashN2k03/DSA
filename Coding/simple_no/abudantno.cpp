#include<iostream>
using namespace std;
int main()
{
	int n,rem,sum,temp;
	sum=0;
	cout<<"enter the number";
	cin>>n;
	for(int i=1;i<n;i++)
	{
		if(n%i==0)
		{
			sum+=i;
		}
	}
 cout<<"sum="<<sum<<endl;
 if(sum>n)
 {
 	cout<<"IT IS ABUDANT NUMBER,ITS ABUDANCE IS==="<<(sum-n);
 	
 }
 else{
 	cout<<"NOT A ABUDANT NO";
 }
}

