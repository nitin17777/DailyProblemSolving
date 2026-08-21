#include<bits/stdc++.h>
#define ll long long
using namespace std;

// void shift(vector<int>&arr)
// {
//     int n = arr.size();

//     int temp = arr[n-1];

//     for(int i = n-1;i>0;i--)
//     {
//         arr[i] = arr[i-1];
//     }
//     arr[0] = temp;
// }
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        //n*n matrix: ai,j = j
        //Ino one op: select row and reverse any subarray in it
        //Sequence of at most 2n ops such that every column contains a permutation of length n

        //Determine the final matrix 

        //The final matrix would have permutstion in every row and column

        //Simply do a cyclic shift of previous row

        // vector<vector<int>>ans;

        // vector<int>prevRow;
        // for(int i = 1;i<=n;i++)
        // {
        //     prevRow.push_back(i);
        // }
        // ans.push_back(prevRow);

        // //Now do a cyclic shift and keep pushing till last row

        // for(int i=2;i<=n;i++)
        // {
        //     shift(prevRow);
        //     ans.push_back(prevRow);
        // }
        

        // for(auto &row:ans)
        // {
        //     for(auto & x:row)cout<<x<<" ";

        //     cout<<endl;
        // }
        // cout<<'\n';



        //We need to output this: row, l, r -> Revrse the elements from l to r in that row

        //We can have atmost 2n ops


        cout<<2*n-1<<'\n';


        for(int i = 1;i<n;i++)
        {
            cout<<i<<" "<<1<<" "<<i<<'\n';
            cout<<i<<" "<<i+1<<" "<<n<<'\n';
        }
        cout<<n<<" "<<"1"<<" " <<n<<'\n';
    }
    return 0;
}