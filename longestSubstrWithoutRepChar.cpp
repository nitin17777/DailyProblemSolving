#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;


    int lengthOfLongestSubstring(string s) 
    {
        //we have to find the length of longest substring without duplicate characters

        //iterate and store string until any already used character is found
        //then return the string with greatest length
        unordered_map<char,int>lastSeen; // for storing the last index of each character

        int n = s.length();
        int start=0;
        int maxLen = 0; // for storing the length of longest substring found so far



        //if the character is already seen and it's inside the current window
        for(int i = 0; i < n; i++)
        {
            if(lastSeen.find(s[i]) != lastSeen.end() && lastSeen[s[i]] >= start)
            {
                //then move the new start to one position right of last occurence
                start = lastSeen[s[i]] +1;            
            }

            lastSeen[s[i]]=i;
            maxLen = max(maxLen,i-start+1);
        }
        return maxLen;
    }

int main()
{

    string s = "abcabcbb";

    int ans = lengthOfLongestSubstring(s);

    cout<<ans<<endl;


    return 0;
}