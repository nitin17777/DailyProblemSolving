#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool checkInclusion(string s1,string s2)
{
    //return true if s2 contains a permutation of s1, else return false

    //find all permutations of s1 and simply find them in s2, return true if found


    if(s1.size() > s2.size())return false;

    vector<int>freqS1(26,0), freqS2(26,0);

    for(char c:s1)
    {
        freqS1[c -'a']++;
    }

    int windowSize = s1.size();

    for(int i=0;i<windowSize;i++)
    {
        freqS2[s2[i] - 'a']++;
    }

    if(freqS1 == freqS2)return true;


    for(int i=windowSize; i<s2.size(); i++)
    {
        //Add new character
        freqS2[s2[i] - 'a']++;

        //remove old character
        freqS2[s2[i-windowSize] -'a']--;


        if(freqS2 == freqS1)return true;
    }

    return false;
}

int main()
{

    string s1 = "ab", s2 = "eidbaooo";
    
    cout<< (checkInclusion(s1,s2) ? "True" : "False")<<endl;

    return 0;

}
