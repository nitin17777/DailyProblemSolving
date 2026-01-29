#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&a,int n)
{

    int k = a.size();

    /*
    2 Operations are : 
    Pick piece ai > 2 and divide it into two pieces -> 1, ai - 1
    Pick slice ai with another slice aj = 1 and merge them into one piece with length ai + 1, due to which arr length would decrease by 1


    Return the min number of ops to restore pie 
    */

    int maxi = *max_element(a.begin(),a.end());
   return 2 * (n - maxi) -k+1;

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

        vector<int>a(k);
        for(auto &x :a)cin>>x;

        cout<<solve(a,n)<<endl;
    }
    return 0;
}