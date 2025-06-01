#include <iostream>
using namespace std;

//PATTERN J

// eg
// enter the number:5

// * 
// * * 
// * * * 
// * * * * 
// * * * * * 
// * * * * 
// * * * 
// * * 
// * 

int main() {
   int n;
   cout<<"enter the number"<<endl;
   cin>>n;
  
   for(int row=1;row<=(n*2)-1;row++)
   {   int rowchange=row>n?(n*2)-row : row;
       for(int col=1;col<=rowchange;col++)
       {   
          cout<<"* ";
       }
      
       cout<<"\n";
   }

    return 0;
}
