#include<iostream>
using namespace std;
int factorial(int num)
{   int fact=1;
    for(int i=1;i<=num;i++)
{	
     fact=fact*i;
}
 return fact;
}
int main(){
	int p,r;
	cout<<"enter people";
	cin>>p;
	cout<<"enter the seats";
	cin>>r;
	int res;
	res=factorial(p)/factorial(p-r);
	cout<<"the no of ways people can be seated"<<res;
}
