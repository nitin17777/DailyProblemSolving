#include<bits/stdc++.h>
#define ll long long
using namespace std;

int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
{
    // Pick exactly k items . return the max possible sum

    int ans = 0;

    
    ans += min(numOnes,k);
    k-= min(numOnes,k);;

    k-=min(numZeros,k);

    ans -= min(numNegOnes,k);
    
    return ans;
}       
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<kItemsWithMaximumSum(3,2,0,2)<<endl;

    return 0;
}