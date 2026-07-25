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

        vector<int>a(n),b(n);
        for(auto& x:a)cin>>x;
        for(auto& x:b)cin>>x;

        //find l and r that could have chosee

        int diffl = -1,diffr= -1;

        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])
            {
                diffr = i;
                if(diffl == -1)diffl = i;
            }
        }

        while(diffl > 0 && b[diffl-1] <= b[diffl])diffl--;

        while(diffr < n-1 && b[diffr+1] >= b[diffr])diffr++;
        
        
        cout<<diffl+1<<" "<<diffr+1<<" "<<'\n';
    }

    return 0;
}