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
        int n,m;
        cin>>n>>m;

        vector<int>a(n);
        for(auto & x:a)cin>>x;

        //For each operation -> Choose a set of carrots,including already chooped carrots

        //Max number of carrots we can sell after using machine exactly 1 time

        //let l = length of carrot , then it is divided into 2 carrrots of size x and l-x

        //if freq of any element is greater than n/2 -> freq*2 + 

        // else return n

        unordered_map<int,int>freq;
        for(auto&x:a)freq[x]++;

        int maxi = 0;

        sort(a.rbegin(),a.rend());

        for(auto &x:freq)
        {
            if(x.second >= n/2)
            {
                freq[(x.first)/2]+= x.second * 2; 
                maxi=max(maxi,freq[x.first/2]);
            }
        }
        cout<<max(maxi*2,n)<<'\n';
    }
    return 0;
}