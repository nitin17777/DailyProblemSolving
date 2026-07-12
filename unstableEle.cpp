#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
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

        //Mark first element and elements i such that ai != ai-1
        //then either delete all those marked elements or duplicate them

        //Determine how many different array of length k can we achieve
        
    
    }

    return 0;
}