#include<iostream>
using namespace std;
 
 void array_left(int arr[],int n,int d)
 {
 	d=d%n;
 	int temp[n];
 	int  i,k=0;
 	for(i=d;i<n;i++)
 	{
 		temp[k]=arr[i];
 		k++;
	 }
	 
	 for(i=0;i<d;i++)
	 {
	 	temp[k]=arr[i];
	 	k++;
	 }
	 
	   for (i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
 }


int main()
{
	int n,a[100],i,d;
	cin>>n;
	cin>>d;
	cout<<"enter the elements";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	array_left(a,n,d);
	cout<<"\n sorted array";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
