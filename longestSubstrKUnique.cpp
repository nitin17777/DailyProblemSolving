#include<bits/stdc++.h>
#define ll long long
using namespace std;

//BRUTE FORCE : SO WE WILL FACE TLE FOR BIGGER INPUTS
int longestKSubstr1(string s,int k)
{

    int n = s.size();

    //Determine substring consisting of exactly k distinct chars,else return -1

    int ans = -1;

    for(int i=0;i<n;i++)
    {
        set<char>st;
        for(int right=i; right<n; right++)
        {
            st.insert(s[right]);
            if(st.size() == k)
            {
                ans = max(ans,right-i+1);
            }

            if(st.size()>k)break;
        }
    }
    return ans;
}


//Optimised approach
int longestKSubstr(string s,int k)
{
    int n=s.size();
    unordered_map<char,int>freq;

    int ans=-1;
    int left = 0;

    for(int right =0;right<n;right++)
    {
        freq[s[right]]++;

        while(freq.size() > k)
        {
            freq[s[left]--];

            if(freq[s[left]]==0)freq.erase(s[left]);
            left++;
        }

        if(freq.size()==k)ans = max(ans,right-left+1);
    }
    return ans;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<longestKSubstr("aabaaab",2)<<endl;

    return 0;
}