#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

long long findMinDiff(vector<long long>a, long long n, long long m)
{
    sort(a.begin(),a.end());
    int i = 0;
    int j = m-1;

    int mini = INT_MAX;

    while(j < a.size())
    {
        int diff = a[j] - a[i];
        mini = min(mini, diff);
        i++;
        j++;
    }
    return mini;
}

int main()
{
    long long n = 8, m = 5;
    vector<long long>a = {3,4,1,9,56,7,9,12};

    long long ans= findMinDiff(a,n,m);
    cout<<ans<<endl;
    
    return 0;
}