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
        vector<int>a(n)l
        for(auto&x:a)cin>>x;

        /*

        k = amazing nums = min number that occurs in all of subsegments in the subsegment of length k, else return -1

        For each k from 1 to n, calculate k amazing number of array a

        
        */

        vector<int>ans(n);

        for(int i = 1;i<=n;i++)
        {
            //Now from 1 to n : We have to check if there is any common number for each window size of i such that it is there in every window or not, iff not simply pushback -1 ?


            //k should atleast be of value = pi+1 - pi
            //also k>=p1 and k>==n-p+1-> Just take min of both

        }
    
    }

    return 0;
}