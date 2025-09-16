#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char,int>freq;
    int n = s.size();

    int left=0;
    int maxLen = 0;

    for(int right = 0;right<n;right++)
    {
        freq[s[right]]++;
            
        while(freq[s[right]] > 1)
        {
            freq[s[left]]--;
            left++; 
        }

        maxLen = max(maxLen , right -left + 1);
    }

    return maxLen;
}

int main()
{
    string s = "abcabcbb";
    cout<<lengthOfLongestSubstring(s)<<endl;

    return 0;
    
}
