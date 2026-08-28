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

        vector<int>a(n*2);
        for(auto& x:a)cin>>x;

        //Each elements occurs exactly twice in the given array

        int score = 0;

        /*Choose an integer x that is present in a
        
        l and r = indices of leftmost and rightmost occurences of x in current array

        Add(r-l+1)^2 to score and delete elements al....ar from the array
        
        
        //find the max score possible after making an array empty

        Find the x with max index diff first , add it's score alomgm with all the intevals occuring bw it


        We should always be deleting the bigger outside interval first



        If l is the first occcurence of a[i] -> dp[i] = max(dp[i-1]+1, dp[l-1]+ ((i-l+1)^2)


        
        
        */


    
    }

    return 0;
}