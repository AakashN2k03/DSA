#include<iostream>
using namespace std;
int main(){
	int num1,num2,lcm;
	cout<<"enter the number";
	cin>>num1;
	cout<<"enter the seconf no";
	cin>>num2;
	if(num1>num2)
	 lcm=num1;
	 else
	  lcm=num2;
	while(true)
	{
		if(lcm%num1==0 && lcm%num2==0){
		
		 cout<<"THE LCM OF "<<num1<<"AND"<<num2<<"IS   "<<lcm;
		 break;
		 
	}
	lcm++;
}
}
