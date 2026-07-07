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
        int n;
        cin>>n;

        vector<int>a(n);
        for(auto& x:a)cin>>x;

        //left 

        vector<int>pref1(n),pref2(n),pref3(n);
        for(int i =0;i<n;i++)
        {
            if(a[i]==1)pref1[i]++;
            else if (a[i]==2)pref[2]++;
            else pref2[i]++;
        }
    
    }

    return 0;
}