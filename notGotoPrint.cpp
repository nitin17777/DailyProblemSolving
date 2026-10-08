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

        //Documents are numbered from 1 to n
        //1-> Scannning -> document is sent to memory and placed in top of everything already there

        //2-> Printing 
        //3 -> quick print

        // Determine the indices that were not printed

        vector<int>memory;

        vector<bool>printed(n+1,false);


        for(int i=1;i<=n;i++)
        {
            if(s[i-1] == '1')
            {
                memory.push_back(i);
            }

            else if(s[i-1] == '2')
            {
                if(!memory.empty())
                {
                    int doc = memory.back();
                    memory.pop_back();

                    printed[doc]=true;
                }

                else printed[i] = true;
            }

            else printed[i] = true;
        }


        vector<int>ans;

        for(int i = 1;i<=n;i++)
        {
            if(!printed[i])ans.push_back(i);
        }        

        cout<<ans.size()<<'\n';
        for(auto&x:ans)cout<<x<<" ";

        cout<<'\n';
        
    }

    return 0;
}