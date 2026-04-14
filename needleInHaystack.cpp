#include<bits/stdc++.h>
#define ll long long
using namespace std;

string solve(string s,string t)
{
    /*

    We have to shuffle string t such that string s appears at aleast once in t as a subsequence

    find the lexicographically smallest one

    and if not possible return IMPOSSIBLE


    start from index 0 to write ->until all frequencies finish , continue till we reach 1st letter of s
    write s -> continue with remaining letter and frequencies
    
    */
    vector<int>freqs(26,0);
    for(auto& x:s)freqs[x -'a']++;

    vector<int>freqt(26);
    for(auto& x:t)freqt[x -'a']++;

    //Now delete frequency of s from t's frequency map
    for(int i = 0;i<26;i++)
    {
        // if t is unable to make s
        if(freqt[i] < freqs[i])return "Impossible";

        //Else remove the frequency of that letter from t
        freqt[i]-=freqs[i];
    }


    string left = "";
    for(int i = 0;i<26;i++)
    {
        left += string(freqt[i],'a' +i);
    }

    //Now merging greedily
    string ans = "";
    int i=0,j=0;

    while(i<s.size() && j < left.size())
    {
        if(s[i] <= left[j])
        {
            ans+=s[i++];
        }
        else
        {
            ans += left[j++];
        }
    }

    while(i<s.size())ans += s[i++];
    while(j<left.size())ans+=left[j++];

    return ans;

    // bool before = true;
    // for(int i = 1;i<s.size();i++)
    // {
    //     if(s[i] != s[0])
    //     {
    //         if(s[i] < s[0])before = false;
            
    //         break;
    //     }
    // }
    // //now go on writing letters -> if first letter of s is smaller than the current runnign letter, write s and then continue writing the letter

    // char first = s[0];
    // string ans="";

    // for(int i = 0;i<26;i++)
    // {
    //     char curr = 'a' + i;

    //     if(curr < first)
    //     {
    //         ans += string(freqt[i],curr);
    //     }

    //     else if(curr == first)
    //     {
    //         if(before)ans+=s;

    //         ans+= string(freqt[i],curr);

    //         if(!before)ans+=s;
    //     }
    //     else 
    //     {
    //         ans += string(freqt[i],curr);
    //     }
    // }

    // //If not inserted till last
    // if(ans.find(s) == string :: npos)ans+=s;

    // return ans;
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




