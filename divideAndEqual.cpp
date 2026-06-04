#include<bits/stdc++.h>
#define ll long long
using namespace std;

void addDivs(int x,map<int,int>&divs)
{
    int i = 2;
    while(i*i <= x)
    {
        while(x% i == 0)
        {
            divs[i]++;
            x/=i;
        }
        i++;
    }
    if(x > 1)divs[x]++;
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

        map<int,int>divs;

        vector<int>a(n);
        for(int i = 0;i<n;i++)
        {
            cin>>a[i];
            addDivs(a[i],divs);
        }            

        bool flag = true;
        for(auto & x:divs)
        {
            if(x.second %n != 0)
            {
                flag = false;
                break;
            }
        }
        cout<<(flag?"Yes":"No")<<endl;
    }

    return 0;
}