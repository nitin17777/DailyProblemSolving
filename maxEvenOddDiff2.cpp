#include<iostream>
#include<unordered_map>
#include<climits>
#include<vector>
using namespace std;

    int maxDifference(string s, int k)
    {
        int maxDiff = INT_MIN;
    //we have to return the max diff: (odd - even) in the substirng of size 'k'


    for(int i = 0; i <= s.length() - k; i++)
    {

        //for each sliding window of size k storing frequency of every character
        
        unordered_map<char,int>freq;
        for(int j = i ; j < i+k; j++)
        {
            freq[s[j]]++;
        }

        vector<int>oddFreq, evenFreq;


         for(auto&[ch,count] : freq)
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
   

    if(!oddFreq.empty() && !evenFreq.empty())
    {
        int maxOdd = *max_element(oddFreq.begin(), oddFreq.end());
        int minEven = *min_element(evenFreq.begin(), evenFreq.end());
        maxDiff = max(maxDiff, maxOdd - minEven);
    }
}

return(maxDiff == INT_MIN)? 0 : maxDiff;

}

int main()
{
    string s = "122333";
    int k = 4;

    int ans = maxDiff(s,k);
    cout<<ans<<endl;

    return 0;

}