#include<bits/stdc++.h>
#define ll long long
using namespace std;
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   
    vector<vector<int>>a(5,vector<int>(5));

        int idxi=0, idxj = 0;
        for(int i=0;i<5;i++)
        {
            for(int j = 0;j<5;j++)
            {
                cin>>a[i][j];

                if(a[i][j] == 1)
                {
                    idxi = i;
                    idxj = j;
                }
            }
        }
        int ans = 0;
        
        ans+= abs(2-idxi);
        ans+=abs(2-idxj);

        cout<<ans<<endl;    
        
        
        return 0;
}