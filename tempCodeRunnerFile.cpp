#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&a)
{
    /*
    1-> Deal 1 damage to any monster alive 
    2-> Deal 1 damage to all alive monster and if a monster dies due to this, repaeat it 

    Spell 2 can be used just once

    Return the min number of times spell 1 can be used
    */

    //Use it when atleast one monster has 1 hp remaining

    //use spell 1 until we have proper counting from 1 to ...

    // check which count we have ,and find the changes required to get it
    
    sort(a.begin(),a.end());
    int n = a.size();

    int hp = 1;
    int ans=0;

    for(int i=0;i<n;i++)
    {
        if(a[i] - hp != 0)
        {
            int needed = a[i]-(hp+1);
            hp++;
            ans+=needed;
        }
    }
    return ans;
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

        vector<int>a(n);
        for(auto& x: a)cin>>x;
        cout<<solve(a)<<endl;
        
    }
    return 0;
}