#include<bits/stdc++.h>
#define ll long long
using namespace std;

int largestAltitude(vector<int>& gain)
{
    int n =gain.size();

    vector<int>pref(n+1);

    pref[0] = 0;

    int maxi = 0;
    for(int i=1;i<=n;i++)
    {
        pref[i]=pref[i-1]+gain[i-1];
        maxi = max(maxi,pref[i]);
    }
    return maxi;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>gain = {-5,1,5,0,-7};
    cout<<largestAltitude(gain)<<endl;

    return 0;
}