#include<bits/stdc++.h>
using namespace std;

int solve(string l,string r)
{
    /*
    Between given two ranges, find 2 numbers such that their strength is the maximum

    to maximise this strength, we need a combo of 0 and 9 at every index possible


    */

    //Padding zeroes to l first, no R padding as R>L
    if(l.size() < r.size())
    {
        l = string(r.size()-l.size(), '0') + l;
    }

    int n = l.size(),ans = 0;

    //Finding first position where both the number differ
    for(int i = 0;i<n;i++)
    {
        if(l[i] != r[i])
        {
            //difference in the first differing digit 
            int diff = (r[i] -'0') - (l[i]-'0');

            ans = diff + 9 * (n-i-1); // 9 * remaining digits
            return ans;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        string L,R;
        cin>>L>>R;

        cout<<solve(L,R)<<endl;
    }
    return 0;
}