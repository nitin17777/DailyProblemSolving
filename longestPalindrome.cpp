#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;


// we have to return the length of the longest possible palindrome from the given word
int longestPalindrome(string s)
{
    unordered_map<char,int>freq;
    for(char ch : s)
    {
        freq[ch]++;
    }

    int length = 0; //for final length of the palindrome

    bool hasOdd = false;

    for(auto & pair : freq)
    {
        int count = pair.second;

        length += (count / 2)*2; // will be even anyways and can be used iin the final word and in case of odd , remaining one can be used as centre later


        if(count %2 == 1)
        {
            hasOdd = true;
        }
    }
    if(hasOdd)
    {
        length += 1;
    }
    return length;
}

int main()
{
    string s = "abccccdd";

    int ans = longestPalindrome(s);

    cout<<ans<<endl;

    return 0;

}