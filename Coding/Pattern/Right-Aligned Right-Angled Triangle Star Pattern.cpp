#include <iostream>
using namespace std;



int main() {
   int n;
   cout<<"enter the number"<<endl;
   cin>>n;
  
   for(int row=1;row<=n;row++)
   {
       for(int space=1;space<=(n-row);space++)
       {
           cout<<" ";
       }
       for(int col=1;col<=row;col++)
       {
           cout<<"*";
       }
       cout<<"\n";
   }

    return 0;
}
