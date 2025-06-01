#include <iostream>
using namespace std;

int main() {
   int n;
   cout<<"enter the number"<<endl;
   cin>>n;
    
   for(int row=1;row<=n;row++)
   {   int zigzag=(row%2==0)?0:1;
       for(int col=1;col<=row;col++)
       {   
           cout<<zigzag<<" ";
           zigzag=!zigzag;
       }
       cout<<"\n";
   }

    return 0;
}
