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

        vector<int>a(n);
        for(auto & x:a)cin>>x;

        //find the indices l,r such that al and are neither max nor min

        int maxi = n;
        int mini = 1;
        bool found = false;
        int l = 0,r= n-1;

        while(l<r)
        {
            if(a[l]==mini)
            {
                l++;
                mini++;
            }

            else if(a[l] == maxi)
            {
                l++;
                maxi--;
            }

            else if(a[r] == mini)
            {
                r--;
                mini++;
            }

            else if(a[r] == maxi)
            {
                r--;
                maxi--;
            }

            else
            {
                cout<<l+1<<" "<<r+1<<endl;
                found = true;
                break;
            }
        }
        if(!found)cout<<-1<<endl;
    }

    return 0;
}