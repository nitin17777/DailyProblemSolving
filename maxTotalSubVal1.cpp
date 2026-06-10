#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll maxTotalValue(vector<int>& a, int k)
{
    int n = a.size();

    /*
    
    Choose exactly k subs and they may overlap
    
    //Val = Max value of sub - Min value of sub

    //Total val = sum of all chosen values
    
    Return max total value we can achieve

    */

    int maxi = *max_element(a.begin(),a.end());
    int mini = *min_element(a.begin(),a.end());

    return 1LL * (maxi-mini) * k;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>a= {1,3,2};
    cout<<maxTotalValue(a,2)<<endl;

    return 0;
}