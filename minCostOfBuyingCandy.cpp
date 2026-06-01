#include<bits/stdc++.h>
#define ll long long
using namespace std;

int minimumCost(vector<int>& cost)
{

    int n = cost.size();
    if(n == 1)return cost[0];

    /*

    For every 2 candies sold, shop gives 3rd candy for free

    Taken away candy should have cost <= other 2 candies


    Determine the min cost of buying all candies
        
    */

    sort(cost.rbegin(),cost.rend());
    int ans = cost[0];
    int ig = 2;


    for(int i = 1;i<n;i++)
    {
        if(i%ig != 0)ans+=cost[i];
        else if(i%ig == 0)ig = ig+=3;
    }
    return ans;

}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>c = {1,2,3};

    cout<<minimumCost(c)<<endl;
    
    return 0;
}