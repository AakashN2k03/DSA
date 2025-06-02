#include <bits/stdc++.h>
using namespace std;

// EG: enter the number 5
// 1 1 1 1 1 1 1 1 1 
// 1 2 2 2 2 2 2 2 1 
// 1 2 3 3 3 3 3 2 1 
// 1 2 3 4 4 4 3 2 1 
// 1 2 3 4 5 4 3 2 1 
// 1 2 3 4 4 4 3 2 1 
// 1 2 3 3 3 3 3 2 1 
// 1 2 2 2 2 2 2 2 1 
// 1 1 1 1 1 1 1 1 1 

int main() {
    
    int n;
    cout<<"enter the number"<<endl;
    cin>>n;
    
    for(int row=1;row<=(n*2)-1;row++)
    {  
        for(int col=1;col<=(n*2)-1;col++)
        {   int top_distance=row;
            int bottom_distance=(n*2)-row;// (n*2-1)-row+1
            int left_distance=col;
            int right_distance=(n*2)-col;
            
          int mini = min({top_distance, bottom_distance, left_distance, right_distance});
            cout<<mini<<" ";
         
        //   cout<<n-mini+1<<" "; // for n to 1 (reverse)
        }
        cout<<"\n";
    }

    return 0;
}
