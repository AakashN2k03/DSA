#include<iostream>
using namespace std;
int main(){
	int num1,num2,a,b;
	cout<<"enter the number";
	cin>>num1;
	cout<<"enter the seconf no";
	cin>>num2;
	a=num1,b=num2;
	while(num1!=num2){
		if(num1>num2)
		{
			num1-=num2;
		}
		else{
			num2-=num1;
		}
	}
	cout<<"hcf of"<<a<<"and "<<b<<"are "<<num1;
	
}
