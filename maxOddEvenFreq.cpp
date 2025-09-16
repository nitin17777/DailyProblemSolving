#include<iostream>
#include<string>
#include<vector>
#include<climits>
#include<unordered_map>
using namespace std;

int maxDiff(string s)
{

    // we have to find the max diff between the character with even frequency and odd frequency

    //1 -> find and store the frequency of every character
    unordered_map<char, int>freq;
    
    for(char c : s)
    {
        freq[c]++;
    }

    vector<int>oddFreq, evenFreq;

    //2 -> then find the character with max even and odd freq
    for(auto[ch,count] : freq)
    {
        if(count %2 == 0)
        {
            evenFreq.push_back(count);
        }
        else
        {
            oddFreq.push_back(count);
        }
    }
    
    //3 -> find the difference
    int maxDiff = INT_MIN;

    for(int odd : oddFreq)
    {
        for(int even : evenFreq)
        {
            maxDiff = max(maxDiff, odd - even);
        }
    }

    return(maxDiff == INT_MIN)? 0 : maxDiff;
    
}

int main()
{

    string s = "aaaaabbc";

    int ans = maxDiff(s);

    cout<< ans <<endl;


    return 0;
     
}