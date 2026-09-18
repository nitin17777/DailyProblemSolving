#include<bits/stdc++.h>
#define ll long long
using namespace std;


vector<int> findSubstring(string s, vector<string>& words)
{
    int n = words.size();
    int m = s.size();

    int wdLen = words[0].size();//Will be similar for all other words as well


    unordered_map<string,int>freq;
    for(auto&x:words)freq[x]++;


    vector<int>ans;

    for(int i=0;i<wdLen;i++)
    {
        int left=i,right=i;

        unordered_map<string,int>wind;

        //We can continue the window if we will find words present in freq in s, else reset the window

        //number of words added to window till now
        int cnt = 0;


        //Taking care of bounds
        while(right+wdLen <= m)
        {
            string word = s.substr(right,wdLen);
            right+=wdLen;

            //Case 1-> Word is not present
            if(freq.find(word)==freq.end())
            {
                //We will clear the window
                wind.clear();
                cnt=0;

                left = right;
                continue;
            }


            wind[word]++;
            cnt++;

            //Case when frequency of that word becomes greater than frequency of that word in 'freq'
            //Removing excessive occurence
            while(wind[word] > freq[word])
            {
                string toRem = s.substr(left,wdLen);
                
                wind[toRem]--;

                left+=wdLen;
                cnt--;
            }


            //When all the words required fromwords  are there
            if(cnt == n)
            {
                ans.push_back(left);
            }
        }
    }
    return ans;   
}
         
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string>words = {"foo","bar"};
    vector<int>ans = findSubstring("barfoothefoobarman",words);

    for(auto & x:ans)cout<<x<<" ";

    cout<<endl;

    return 0;
}