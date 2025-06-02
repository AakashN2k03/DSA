#include <iostream>
using namespace std;
int main() {
    
    int n;
    cout<<"enter the number"<<endl;
    cin>>n;
    
    for(int row=1;row<=n*2;row++)
    {   int rowchange=row>n?(n*2)-row+1 :row;
        for(int col=1;col<=n*2;col++)
        {
            if(col<= n-rowchange+1 || col>n+rowchange-1)
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
