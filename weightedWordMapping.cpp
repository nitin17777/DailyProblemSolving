#include<bits/stdc++.h>
#define ll long long
using namespace std;


string mapWordWeights(vector<string>& words, vector<int>& weights)
{
    string ans = "";

    for(auto & x:words)
    {
        int weight = 0;

        for(char&ch:x)
        {
            weight += weights[ch - 'a'];
        }

        weight %= 26;

        ans += ('z'-weight);
    }
    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string>w = {"abcd","def","xyz"};
    vector<int>we ={5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2};
    
    cout<<mapWordWeights(w,we)<<'\n';

    

    return 0;
}