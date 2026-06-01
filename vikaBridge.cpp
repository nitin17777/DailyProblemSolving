#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<int>&a,int k,int n)
{
    /*

    n planks are there in bridge and only k cans of paint are there
    Painted each plank with one of the k colors

    Walk on the paint of same color
    Can only repaint one plank 

    Determine the max possibble she can take to cross in one step if she can repaint one plank of different color while bridge crossing
    
    
    */
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;


        vector<int>a(n);
        for(auto & x:a)cin>>x;

        cout<<solve(a,k,n)<<endl;
    
    }

    return 0;
}