#include<bits/stdc++.h>
#define ll long long
using namespace std;

int closestTarget(vector<string>& words, string target, int startIndex)
{
    int n = words.size();

    //We can either move 1 step forward or 1 step back at a time 
    //Return the shortest distance to reach the string target, if not in array return -1

    int ans = INT_MAX;
    for(int i = 0; i<n; i++)
    {
        if(words[i] == target)
        {
            int dist = abs(i-startIndex);


            //min(dist,n-dist) -> to check from which side it's shorter
            ans = min(ans,min(dist,n-dist));
        }
    }
    return ans == INT_MAX?-1: ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string>w = {"hello","i","am","leetcode","hello"};
    cout<<closestTarget(w,"hello",1)<<endl;

    return 0;
}




