#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int maxFreqSum(string s)
{
    //find the frequency of most occcuring vowel and consonant and add their frequencies

    int vowelFreq = 0,consFreq = 0;

    unordered_map<char,int>freq;

    for(char&c :s)
    {
        freq[c]++;
    }

    string vowel = "aeiou";

    //now find the max freq of vowel, i.e from aeiou
    for(char v : vowel)
    {
        vowelFreq = max(vowelFreq, freq[v]);
    }

    for(char c = 'a';c<='z';c++)
    {
        if(vowel.find(c) == string::npos) // if current character is not a vowel
        {
            consFreq = max(consFreq,freq[c]);
        }
    }
    //and then find the max freq of consonant from hash table

    int sum = consFreq + vowelFreq;
    return sum; 
}

int main()
{
    cout<<maxFreqSum("successes")<<endl;
    return 0;
    
}
