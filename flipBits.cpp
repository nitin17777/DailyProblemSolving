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

        string a,b;
        cin>>a>>b;

        a.push_back('0');
        b.push_back('0');


        //Transform string a into b

        //Select any prefix with equal number of zeros and ones and invert       
        int cnt =0;

        bool ok = true;
        for(int i = 0;i<n;i++)
        {
            cnt+=(a[i]=='1')-(a[i]=='0');

            if((a[i]==b[i]) != (a[i+1]==b[i+1]) && cnt != 0)
            {
                ok = false;
                break;
            }
        }
        cout<<(ok?"Yes":"No")<<'\n';
    }
    return 0;
}