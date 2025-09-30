#include<bits/stdc++.h>
using namespace std;

string frequencySort(string s)
{
    //character with highest frequency would come first in resultant string and if same frequency, string will be in alphabetical order


    unordered_map<char,int>freq;
    
    for(char c: s)
    {
        freq[c]++;
    }

    //moving to vector for sorting
    vector<pair<char,int>>vec(freq.begin(), freq.end());


    sort(vec.begin(),vec.end(), [](auto&a,auto&b)
    {
        if(a.second == b.second)
        {
            return a.first < b.first;
        }
        return a.second> b.second;
    });

    string result = "";

    for(auto&p : vec)
    {
        result.append(p.second,p.first);//append p.first character for p.second times
    }
    return result;
}


int main()
{
    cout<<frequencySort("tree")<<endl;
        return 0;

}