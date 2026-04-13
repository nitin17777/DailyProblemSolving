#include<bits/stdc++.h>
#define ll long long
using namespace std;

string solve(string s,string t)
{
    int n = s.size(),m = t.size();


    /*


    We have to shuffle string t such that string s appears at aleast once in t as a subsequence

    find the lexicographically smallest one

    and if not possible return IMPOSSIBLE


    start from index 0 to write ->until all frequencies finish , continue till we reach 1st letter of s
    write s -> continue with remaining letter and frequencies
    
    */

    string ans;

    vector<int>freqs(26);
    for(auto& x:t)freq[x -'a']++;

    vector<int>freqt(26);
    for(auto& x:t)freq[x -'a']++;

    




    sort(ans.begin(),ans.end());




}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        string n,m;
        cin>>n>>m;

        cout<<solve(n,m)<<endl;
    }

    return 0;
}




