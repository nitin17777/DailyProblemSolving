#include<bits/stdc++.h>
#define ll long long
using namespace std;

int maxProduct(int n)
{
    int t = n;
    vector<int>arr;

    while(t)
    {
        arr.push_back(t%10);
        t/=10;
    }
    sort(arr.begin(),arr.end());
    return arr[arr.size()-1]*arr[arr.size()-2];
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   
    cout<<maxProduct(31)<<endl;
    return 0;
}