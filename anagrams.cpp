#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    int n = strs.size();

    //we need to group the anagrmas together

    //anagrams -> Words formed by arranging same letters exactly same numebr of times
    vector<vector<string>>ans;

    unordered_map<string, vector<string>>mp;

    for(auto s:strs)
    {
        string key = s;
        sort(key.begin(),key.end());

        mp[key].push_back(s);
    }

    for(auto & it:mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   vector<string>strs = {"eat","tea","tan","ate","nat","bat"};

   vector<vector<string>>ans = groupAnagrams(strs);

   for(auto& x:ans)
   {
        for(auto& y:x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
   }
   cout<<endl;

    return 0;
}