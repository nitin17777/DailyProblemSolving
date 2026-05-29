#include<bits/stdc++.h>
#define ll long long
using namespace std;

int minElement(vector<int>& a)
{

    int mini = INT_MAX;

    for(auto & x:a)
    {
        int sum = 0;
        int t = x;

        while(t>0)
        {
            sum+=t%10;
            t/=10;
        }
        mini = min(mini,sum);
    }
    return mini;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>a = {10,12,13,14};
    cout<<minElement(a)<<endl;

    return 0;
}