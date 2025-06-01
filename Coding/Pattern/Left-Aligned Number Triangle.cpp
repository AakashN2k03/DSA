#include <iostream>
using namespace std;

int main() {
   int n;
   cout<<"enter the number"<<endl;
   cin>>n;
   for(int row=1;row<=n;row++)
   {
       for(int col=1;col<=row;col++)
       {
           cout<<col<<" ";
       }
       cout<<"\n";
   }

    return 0;
}
