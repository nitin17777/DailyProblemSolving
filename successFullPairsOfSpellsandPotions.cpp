#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{
    // sort the potions and find the point below which each strength would be less
    int m = potions.size(), n = spells.size();
    sort(potions.begin(), potions.end());
    vector<int> ans;

    for (int spell : spells)
    {
        ll minPotion = (success + spell - 1) / spell;

        auto it = lower_bound(potions.begin(), potions.end(), minPotion);

        int count = potions.end() - it;

        ans.push_back(count);
    }
    return ans;
}

/* Time Limit Exceeded

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
{
    //a spell and potion pair is considered successful if product their strength is at least success

    //mutiply spells[i] by each element of potions and if product is greater than success , increase the count for that spell
    vector<int>ans;

    for(int i = 0;i<spells.size();i++)
    {
        int count=0;
        for(int j =0;j<potions.size();j++)
        {

            int strength = spells[i] * potions[j];
            if(strength >= success)count++;
        }
    ans.push_back(count);//push number of successful pairs
    count = 0;//and now reset the counter
    }
    return ans;
}
    */

int main()
{
    vector<int> spells = {5, 1, 3};
    vector<int> potions = {1, 2, 3, 4, 5};

    vector<int> ans = successfulPairs(spells, potions, 7);

    for (auto &an : ans)
    {
        cout << an << " ";
    }
    cout << endl;

    return 0;
}
