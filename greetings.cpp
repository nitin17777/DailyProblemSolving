#include<bits/stdc++.h>
#define ll long long
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


int main()
{

    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<pair<int,int>>arr;

        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            arr.push_back({y,x});
        }

        ll ans = 0;
        ordered_set st;

        sort(arr.begin(),arr.end());

        for(auto p : arr)
        {
            //Counting how many previously processed a valuesa re greater than equal to current p.second;
            ans += st.size()-st.order_of_key(p.second);

            st.insert(p.second);
        }

        cout<<ans<<'\n';
    }
// class Fenwick
// {
//     int n;
//     vector<int>bit;

//     public:
//         Fenwick(int n)
//         {
//             this->n = n;
//             bit.assign(n+1,0);
//         }

//         void update(int idx,int val)
//         {

//             while(idx<=n)
//             {
//                 bit[idx]+=val;

//                 //And move to next fenwick block
//                 idx+= idx & -idx;
//             }
//         }


//         //Returns sum from 1 to idx
//         int query(int idx)
//         {
//             int sum = 0;

//             while(idx>0)
//             {
//                 sum += bit[idx];

//                 //And move to previous fenwick block now
//                 idx-= idx&-idx;
//             }
//             return sum;
//         }
// };

      
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin>>t;

//     while(t--)
//     {
//         int n;
//         cin>>n;

//         vector<pair<int,int>>a;
//         for(int i=0;i<n;i++)
//         {
//             int x,y;
//             cin>>x>>y;

//             a.push_back({y,x});
//         }
//         /*

//         ith person wants to go from ai to bi

//         All start moving at speed of 1 unit per second until they reach bi 
//         And when two people meet -> a greeting happens

//         Determine how many greetings would be there in total


//         Two people will meet when ones range is fully contained inside that of other's
        

//         For every (a,b) among previously processed segments -> count how many have starting point greater than current a -> And to do this, we will be using fenwick tree
    
//         Our fenwick tree will store starting points of previously processed segments


//         */

//         //Sorting based on basis of ending points
//         sort(a.begin(),a.end());

//         //Now using fenwick tree to store starting points fof previously processed segments 

//         Fenwick fw(n);
//         ll ans = 0;
//         int processed = 0;

//         for(auto [b,start]:a)
//         {

//             //Gives how many previously processed starting points are greater than current start****
            
//             int smallerOrEqual = fw.query(start);
//             int greater = processed - smallerOrEqual;

//             ans+=greater;

//             //Adding current starting point
//             fw.update(start,1);
//             processed++;
//         }
//         cout<<ans<<'\n';
//     }

    return 0;
}