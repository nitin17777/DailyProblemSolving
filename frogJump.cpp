#include<bits/stdc++.h>
using namespace std;

bool canCross(vector<int>& stones)
{
    int n = stones.size();

    //Determine if frog can jump in the last stone and first jump is of 1 unit only

    //If current jump = k units, next jump should be of k-1 , k or k+1 units

    unordered_map<int,unordered_set<int>>mp;

    for(int stone: stones)mp[stone] = {};

    mp[0].insert(0);//starting from stone 0 with prev jump of 0 unnits

    for(int stone:stones)
    {
        //For each jump size k that can reach stone
        for(int k: mp[stone])
        {
            for(int jump = k-1;jump<=k+1;jump++)
            {
                if(jump>0)
                {
                    int nextStone = stone + jump;

                    //Checking if a stone exists at this position
                    if(mp.count(nextStone))
                    {
                        //Recording that we can reach that stone with this jump
                        mp[nextStone].insert(jump);
                    }
                }
            }
        }
    }
    
    //IF last stone has any valid jump that reaches it, return true;
    return !mp[stones.back()].empty();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>stones = {0,1,3,5,6,8,12,17};
    cout<<(canCross(stones)?"True":"False")<<endl;
    return 0;
}