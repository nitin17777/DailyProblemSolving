#include<bits/stdc++.h>
#define ll long long
using namespace std;

string solve(string& s, int n, int k) {
    string ans(n, '0');

    stack<int> st;
    vector<pair<int,int>> pairs;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') st.push(i);
        else if (!st.empty()) {
            pairs.push_back({st.top(), i});
            st.pop();
        }
    }

    int d = min(k, (int)pairs.size());
    for (int i = 0; i < d; i++) {
        // Mark the '(' for removal, not the ')'
        ans[pairs[pairs.size() - 1 - i].first] = '1';
    }

    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;


        string s;
        cin>>s;

        string ans = solve(s,n,k);

        for(auto & x:ans)cout<<x;

        cout<<endl;
    
    }

    return 0;
}