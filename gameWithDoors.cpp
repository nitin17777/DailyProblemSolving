#include <bits/stdc++.h>
using namespace std;

int solve(int l,int r,int L, int R)
{

    /*

    ith door connects room i and i+1

    We can reach from room x to y if all the doors in bw them are unlocked

    Return the min number of doors to lock to avoid their meeting


    if ranges dont' overlap -> then ans = 1

    if(ranges are overlapping) -> Then we need to close very door that is in overlappping range + 1 door just before this range + 1 door just after this range
    */

    // bool o1=false,o2=false;

    // int ans =0 ;
    // int overlapping1=0,overlapping2=0;
    // if(L <= l && l <= R)
    // {

    //     overlapping1  = r-l;
    //     o1 = true;
    // }

    // else if(l<=L && L<=r)
    // {
    //     overlapping2  = R-L;
    //     o2 = true;
    // }

    // if(!o1 && !o2)return 1;

    // //same range
    // if(o2&o1)return r-l;
    
    // if(r!=R)ans++;
    // if(l!=L)ans++;

    // ans+=overlapping1+overlapping2;

    // return ans;

    int inter = min(r,R)-max(l,L)+1;

    int ans = inter -1;


    if(inter<=0)ans=1;

    else
    {
        ans+=(l!=L);
        ans+=(r!=R);
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int l,r,L,R;
        cin >>l>>r>>L>>R;


        cout<<solve(l,r,L,R)<<endl;


    }
    return 0;
}