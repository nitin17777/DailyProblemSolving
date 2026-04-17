#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> solve(int a, int b)
{
    /*

    An array is beautiful if it's mean = a and median = b

    Find such array

    Mean = sum / length = a
    Median = mid element = b
    
    */


    // Place median in mid and we can manage mean accordingly

    vector<int>ans(3);

    ans[1] = b;

    ans[0] = b;


    //Since the array must be sorted as well, because median is mid element in case of sorted array only
    ans[2] = a*3 - 2*b;

    return ans;  

}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b;
    cin>>a>>b;

    vector<int>ans = solve(a,b);

    cout<<ans.size()<<endl;

    for(auto & x:ans)cout<<x<<" ";

    cout<<endl;


    return 0;
}