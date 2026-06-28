#include<bits/stdc++.h>
#define ll long long
using namespace std;

int maximumElementAfterDecrementingAndRearranging(vector<int>& a)
{
    int n = a.size();

    //1st element is 1 and differnece bw adjacent element <= 1

    //Ops = 1-> Decrease value of element to any lower value
    //      2-> Rearrange the value of arr to any order

    //Return the max possible value in arr after performing this ops

    sort(a.begin(),a.end());
    a[0] = 1;

    for(int i =1;i<n;i++)
    {
        a[i]=min(a[i],a[i-1]+1);
    }
    return a[n-1];
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>a = {2,2,1,2,1};
    cout<<maximumElementAfterDecrementingAndRearranging(a)<<'\n';

    return 0;
}