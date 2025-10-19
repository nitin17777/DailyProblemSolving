#include <bits/stdc++.h>

using namespace std;

int maxPartitionsAfterOperations(string s, int k)
{
    int n = s.size();

    map<tuple<int, int, int>, int> memo;
}

/* GETTING TLE WITH THIS METHOD

//counting partitions using greedy rule

int countPartitions(const string&s,int k)
{
    int cnt = 0;
    unordered_map<char,int>freq;
    int distinct = 0;

    for(char c:s)
    {
        freq[c]++;

        if(freq[c] == 1)distinct++;

        if(distinct> k)
        {
            cnt++;
            freq.clear();//clear the entire freq map

            //now reset
            freq[c] = 1;
            distinct = 1;

        }
    }

    if(!freq.empty()) cnt++;
    return cnt;
}

int maxPartitionsAfterOperations(string s, int k)
{
    //firstly we are allowed to changed atmost one index in s to another letter

    //Then until s is empty:
    //choose longest prefix of s containing at most k distinct characters

    //delete the prefix from s and increase the number of partitions by one

    //return the max number of resulting partitions

    int n = s.size();

    int maxParts = countPartitions(s,k);

    for(int i = 0; i <n;i++)
    {
        char original = s[i];

        for(char ch = 'a';ch<='z';ch++)
        {
            if(ch == original)continue; //skipping same char

            s[i] = ch; //else exchange

            int parts = countPartitions(s,k);
            maxParts = max(maxParts,parts);
        }
        s[i] = original;

    }
    return maxParts;
}
*/
int main()
{
    string s = "acccs";
    cout << maxPartitionsAfterOperations(s, 2) << endl;

    return 0;
}
