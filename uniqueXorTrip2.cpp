#include<bits/stdc++.h>
#define ll long long
using namespace std;

int uniqueXorTriplets(vector<int>& nums)
{
    int n = nums.size();

    //since every xor value is at most 2047(11 bits)
    const int MAXX = 2048;

    //pair[x] = true if there exists a pair (j,k) with  j < = k whose XOR is x
    vector<int>pair(MAXX,0);

    //ans[x] = true if this x can attained as XOR
    vector<int>ans(MAXX,0);

    for(int i=n-1;i>=0;i--)
    {
        for(int k=i;k<n;k++)
        {
            pair[nums[i]^nums[k]] = 1;
        }

        for(int x=0;x<MAXX;x++)
        {
            if(pair[x])ans[x ^nums[i]]=1;
        }
    }
    int res = 0;
    for(int v:ans)res+=v;

    return res;   
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>a = {1,3};
    cout<<uniqueXorTriplets(a)<<'\n';

    return 0;
}