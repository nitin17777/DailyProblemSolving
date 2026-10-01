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

        
        vector<tuple<int,int,int>>a;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            a.push_back({x,y,i});
        }

        /*

        Divide all segments into two non empty groups such that there is no pair of segments from different groups which have atlease one common point or determine if it is impossible to do so.
        Each segment belongs to exactly one group 

        1-> If it belongs to 1st group
        2-> If it belongs to 2nd group 
        else return -1

        Both groups should be non empty


        Division is possibel iff union consists of atleast 2 disconnected com

        */
       sort(a.begin(),a.end());

       //suffMin = min left endpoint
       vector<int>suffMin(n);

       suffMin[n-1] = get<0>(a[n-1]);

       for(int i = n-2;i>=0;i--)
       {
            suffMin[i] = min(get<0>(a[i]),suffMin[i+1]);
       }

       //Findiing position where there is a gap
       int prefMax=INT_MIN;
       int cut = -1;


       for(int i = 0;i<n-1;i++)
       {
            prefMax = max(prefMax,get<1>(a[i]));

            //If left part ends before right part starts 
            if(prefMax<suffMin[i+1])
            {
                cut=i;
                break;
            }
        }

        if(cut==-1)
        {
            cout<<-1<<'\n';
            continue;
        }

        vector<int>ans(n);

        //Left part -> group 1
        for(int i=0;i<=cut;i++)
        {
            int oriIdx = get<2>(a[i]);
            ans[oriIdx] = 1;
        }

         // Right part -> group 2
        for (int i = cut + 1; i < n; i++)
        {
            int oriIdx = get<2>(a[i]);
            ans[oriIdx] = 2;
        }

        for(auto & x:ans)cout<<x<<" ";

        cout<<'\n';
    }

    return 0;
}