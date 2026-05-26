#include <bits/stdc++.h>
using namespace std;

bool isPos(vector<int> &b,int n)
{

    //Choose an integer less than x and increment it by x

    //Determine if we can wver reach array b

    int mini = b[0];

    for(auto & x:b)
    {
        if(x>=2*mini)return false;

        mini = min(mini,x);
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        cout << (isPos(a,n) ? "Yes" : "No") << endl;
    }
    return 0;
}