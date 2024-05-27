#include<iostream>
using namespace std;
int main()
{
	string s,v;
	int i,j=0;
	cout<<"enter the string";
	getline(cin,s);
	for(i=0;s[i]!='\0';i++)
	{
	
	if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
		v[j]=s[i];
		j++;
	}
}
  v[j]='\0';
  	for(i=0;v[i]!='\0';i++)
	{
        cout<<v[i];
}
}
