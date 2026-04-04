#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int l = 1, r = 3*n;

        vector<int> ans;

        while(l < r)
        {
            ans.push_back(l);
            ans.push_back(r-1);
            ans.push_back(r);

            l++;
            r -= 2;
        }

        for(int x : ans)
            cout << x << " ";
        cout << endl;
    }
}