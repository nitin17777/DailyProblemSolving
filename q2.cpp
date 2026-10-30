#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<int>&a)
{
    /*
    Initial n weights are there

    Adds load to each weight based on permutation from 1 to n

    w[i] += p[i]

    max number of weights that can have same final load


    
    */

    sort(a.begin(),a.end());

    a.erase(unique(a.begin(),a.end()), a.end());

   int n = a.size();

   int l = 0;

   int best = 0;
   for(int r = 0;r<n;r++)
   {
        while((ll)a[r]-a[l] >=n)l++;
        best = max(best, r-l+1);
   }
   return best;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>w = {1,2,2,4,6};
    cout<<solve(w)<<endl;

    
    return 0;
}