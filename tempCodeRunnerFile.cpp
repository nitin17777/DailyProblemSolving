#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
    

        vector<int>a(n);
        for(auto&x:a)cin>>x;

        unordered_map<int,int>freq;
        for(auto &x:a)freq[x]++;

        sort(a.begin(), a.end());

        /*

        Mode = number that appears max number of times

        Arrange such that sum of modes over all the prefixe of the array is maximised

        //Put max element at first, then start putting elements with least frequency -> highest frequency
        */

        int maxi = *max_element(a.begin(),a.end());

        vector<int>ans;
        
        int maxiFreq = freq[maxi];
        int maxFreq=maxiFreq;


        while(maxFreq--)
        {
            ans.push_back(maxi);
        }


        /////////////////////////////////////

       
        //Now push at maximum: freq[maxi] of all elements in any order

        //and when done with that start pushing from 2nd largest element
        for(auto&[num,f] : freq)
        {
            if(num!=maxi)
            {
                int reqFreq = min(freq[num],maxFreq);
                f-=reqFreq;
                while(reqFreq--)
                {
                    ans.push_back(num);
                }
            }
        }

        //now push remaining elements
        for(auto&[num,f] : freq)
        {
            while(f--)
            {
                ans.push_back(num);
            }
        }

        for(auto & x:ans)cout<<x<<" ";
        cout<<'\n';
    }

    return 0;
}