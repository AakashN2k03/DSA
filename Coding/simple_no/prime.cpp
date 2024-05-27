#include<iostream>
using namespace std;
int main()
{
	 int no,count=0;
	 cout<<"enter number";
	 cin>>no;
	 for(int i=1;i<=no;i++)
	 {  if(no%i==0)
	   
	    count=count+1;
	 }
	 if (no==0||no==1)
	 {
	 	cout<<" not prime no";
	 }
	 else if(count>2){
	 	cout<<" not a prime";
	 }
	 else{
	 	cout<<"  prime number";
	 }
}
