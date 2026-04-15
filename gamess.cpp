#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<int>&a,vector<int>&b,int n ,int m)
{
    //Both a and b has atleast 1 number in common
    

    //Determine the max possible number of suggestions they will make while choosing the game

    //to maximise the count -> They should save that common number for last
    

    //Calculate unique numbers from both , and use : 2*min(x,y) + 2 -> x>y
                                                    // 2 * min(x,y) + 1 else
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(a[i] == b[j])cnt++;
        }
    }
    int x = n-cnt;
    int y = m-cnt;

    if(x>y)return 2*min(x,y)+2;
    
    return 2* min(x,y) +1;


}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,m;
        cin>>n>>m;

        vector<int>a(n),b(m);
        for(auto & x:a)cin>>x;
        for(auto & x:b)cin>>x;

        cout<<solve(a,b,n,m)<<endl;
    
    }

    return 0;
}




