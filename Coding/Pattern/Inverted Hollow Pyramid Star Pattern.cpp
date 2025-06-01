#include <iostream>
using namespace std;
int main() {
   int n;
   cout<<"enter the number"<<endl;
   cin>>n;
    // Inverted Pyramid Star Pattern
  for(int row=n;row>0;row--)
   {
       for(int space=1;space<=(n-row);space++)
       {
           cout<<" ";
       }
       for(int col=1;col<=(2*row-1);col++)
       {    if(col==1 || col==2*row-1 || row==n)
             {
               cout<<"*";
             }
             else{
                 cout<<" ";
             }
       }
       cout<<"\n";
   }
    return 0;
}
