#include <iostream>
using namespace std;
int main() {
   int n;
   cout<<"enter the number"<<endl;
   cin>>n;
  
   for(int row=n;row>0;row--)
   {
       for(int space=1;space<=(n-row);space++)
       {
           cout<<" ";
       }
       for(int col=1;col<=(2*row-1);col++)
       {
           cout<<"*";
       }
       cout<<"\n";
   }

    return 0;
}
