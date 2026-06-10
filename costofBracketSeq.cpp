#include<bits/stdc++.h>
#define ll long long
using namespace std;

string solve(string& s, int n, int k) 
{

    vector<int>prefOpen(n+1),prefClose(n+1);

    for(int i = 0;i<n;i++)
    {
        prefOpen[i+1] = prefOpen[i] + (s[i]=='(');
        prefClose[i+1] = prefClose[i] + (s[i] == ')');
    }

    //so total close brackets now:
    int totalClose = prefClose[n];

    int pos = n;

    for(int i = 0;i<n;i++)
    {
        if(prefOpen[i] + totalClose-prefClose[i] < prefOpen[pos] + totalClose-prefClose[pos])pos = i;
    }

    string ans(n,'0');

    //Finding the perfect cut now
    for(int i =0 ;i<pos;i++)
    {
        if(k>0 && s[i] == '(')
        {
            ans[i] = '1';
            k--;
        }
    }


    for (int i = pos; i < n; i++)
    {
		if (k > 0 && s[i] == ')')
        {
			ans[i] = '1';
			k--;
		}
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