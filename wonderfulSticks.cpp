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

        string s;
        cin>>s;

        int l = 1,r=n;

        vector<int>a(n);

        for(int i = n-2;i>=0;i--)
        {
            if(s[i] == '<')
            {
                a[i+1]=l;
                l++;
            }

            if(s[i]=='>')
            {
                a[i+1]=r;
                r--;
            }
        }
        a[0]=l;

    
        for (int i = 0; i < n; i++)cout << a[i] << " ";

        cout<<endl;
    }

    return 0;
}