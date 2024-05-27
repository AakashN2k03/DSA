#include<iostream>
using namespace std;
int main()
{
	char t[100];
	int i,j;
	cout<<"enter the character";
	 cin.getline(t, 100);
     char s[100];
      j=0;
	for( i=0;t[i]!='\0';i++){
	
	if(!(t[i]=='a'||t[i]=='e'||t[i]=='i'||t[i]=='o'||t[i]=='u'||t[i]=='A'||t[i]=='E'||t[i]=='I'||t[i]=='O'||t[i]=='U'))
	{    s[j]=t[i];
     	j++;
	
} 
s[j]='\0';

	

}	cout<<"\n string after removal of vowels"<<s;}
