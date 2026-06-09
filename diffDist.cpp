#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
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

        /*
        1...n appears exactly 4 times
        pxi = ith occurence of x in array


        solution Firstly 2 together and then normal counting twice


        */

        vector<int>ans;
        if (n % 2 == 0) {
            for (int i = 1; i <= n; i++) ans.push_back(i);
            for (int i = 1; i <= n; i++) ans.push_back(i);
            for (int i = n; i >= 1; i--) ans.push_back(i);
            for (int i = 1; i <= n; i++) ans.push_back(i);
        }
        else {
            // Base for n = 3
            vector<int> base = {1,1,2,1,2,3,1,3,2,2,3,3};
            for (int x : base) ans.push_back(x);

            // Even construction for 4..n
            for (int i = 4; i <= n; i++) ans.push_back(i);
            for (int i = 4; i <= n; i++) ans.push_back(i);
            for (int i = n; i >= 4; i--) ans.push_back(i);
            for (int i = 4; i <= n; i++) ans.push_back(i);
        }

        for(auto&x:ans)cout<<x<<" ";

        cout<<endl;
    
    }

    return 0;
}