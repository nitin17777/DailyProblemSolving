#include<iostream>
#include<vector>
using namespace std;

bool checkInclusion(string s1, string s2)
{    
    if(s1.size() > s2.size())
    return false;

    vector<int>freqS1(26,0), freqWin(26,0);

    for(char c : s1)
    {
        freqS1[c-'a']++;
    }

    int windowSize = s1.size();



    //initial window 
    for(int i = 0; i<windowSize; i++)
    {
        freqWin[s2[i]-'a']++;
    }

    if(freqWin == freqS1)
    return true;

    
    for(int i = windowSize; i<s2.size(); i++)
    {
        freqWin[s2[i] - 'a']++;

        freqWin[s2[i-windowSize] -'a']--;

        if(freqWin == freqS1)

        return true;

    }
    return false;
    
}

    // for(auto&nu :s1)
    // {
    //     freqS1[nu]++;
    // }

    // int windowSize = s1.length();
    
    // unordered_map<char,int>freqS2;

    // for(auto &nn : s2)
    // {
    //     freqS2[nn]++;
    // }


    // //checking is 1st window is a permutation
    // if(freqS2 == freqS1)
    // return true;


    // for(int i = windowSize; i < s2.length();i++)
    // {
    //     char newChar = s2[i];

    // }

int main()
{

    string s1 = "ab";
    string s2 = "eidbaooo";

    cout<<(checkInclusion(s1,s2) ? "True" : "False");

    return 0 ;
}