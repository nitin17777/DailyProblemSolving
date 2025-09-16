#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


//using XOR(Best)
char findDiff(string s,string t)
{
     char result = 0;
    for(char ch : s)
    result ^= ch; // We used XOR here because same letter's XOR cancels it

    for(char ch : t)
    result ^= ch;

    return result;
}

//using hashMap
char findDifff(string s,string t)
{
    unordered_map<char,int>count;

    for(char ch : s)
    count[ch]--;

    for(char ch :t)
    count[ch]++;

    for(auto & diff : count)
    {
        if(diff.second > 0)
        {
            return diff.first;
        }
    }
    return ' ';

}


int main()
{

    string s = "abcde";
    string t = "abcd";

    char diff = findDifff(s,t);
    cout<<diff<<endl;

    return 0;

}