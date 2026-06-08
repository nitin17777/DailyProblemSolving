#include<bits/stdc++.h>
#define ll long long
using namespace std;

string solve(string&s,int k,int n)
{
    //Alice -> IF she can transform all chars of s into zeroes

    //In each turn Alice changes a subsequence of length k to 0 
    
    //Bob chooses substring of length k and changes to  1 

    //If length fo longest consecutive 1s >= k ->bob, else alice
    int cnt =0;

    //Bob can win if before Alice's turn there are at least

    for(char&c:s)if(c == '1')cnt++;
    
    if(cnt <= k || n < 2*k)return "Alice";
    //n < 2*k condition because: 

    else return "Bob";
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;

        string s;
        cin>>s;

        cout<<solve(s,k,n)<<endl;
    }

    return 0;
}