#include<iostream>
using namespace std;
int main()
{
	int number;
	cout<<"ENTER THE NO TO FIND FACTORS";
	cin>>number;
	cout<<"\n THE FACTORS ARE:\n";
	for(int i=1;i<=number;i++){
		if(number%i==0){
			cout<<i<<"\n";
		}
	}
}
