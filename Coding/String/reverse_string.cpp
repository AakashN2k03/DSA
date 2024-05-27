#include<iostream>
using namespace std;
int main(){
	char a[100],b[100];
	cout<<"enter the name";
	gets(a);
	int i,j,count=0;
	for(i=0;a[i]!='\0';i++)
	{
		count++;
	} 
    	j=0;
	for(i=count-1;i>=0;i--)
	{
		b[j]=a[i];
		j++;
			}
        a[j]='\0';
	
	for(j=0;b[j]!='\0';j++)
	{
		cout<<b[j];
	}
					
}
