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
        for(auto& x:a)cin>>x;

        /*
        Labels on the component form a permutation of length n

        We can do this only once: 
        Choose m integers and reverse elements at those chosen indices

        Determine if he can sort the array by doing so

        */

       vector<int>miss;
       for(int i =0;i<n;i++)
       {
            if(a[i]!=i+1)miss.push_back(a[i]);
       }

       reverse(miss.begin(),miss.end());

       cout<<(is_sorted(miss.begin(),miss.end())? "Yes":"No")<<'\n';
    }

    return 0;
}