#include<bits/stdc++.h>
using namespace std;

int guessNumber(int n)
{
    int l=1,r=n;

    while(l<=r)
    {
        int mid = l + (r-l)/2;

        int res = guess(mid);

        if(res == 0)return mid;
        else if(res == -1)high = mid-1;
        else low = mid+1;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
    }
    return 0;
}