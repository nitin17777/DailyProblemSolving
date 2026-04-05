#include<bits/stdc++.h>
using namespace std;

int minJumps(vector<int>& arr)
{
    int n = arr.size();
    if(n<=1)return 0;
    if(arr[0] == 0)return -1;


    //Min jumps to move from first posi to lasr posi

    int jumps = 0,currEnd = 0,maxReach = 0;

    for(int i = 0;i<n-1;i++)
    {
        maxReach = max(maxReach,i+arr[i]);

        if(i == currEnd)
        {
            jumps++;
            currEnd = maxReach;

            if(currEnd >= n-1)return jumps;
        }
        if(i>=maxReach)return -1;
    }
    return jumps;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>a = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    cout<<minJumps(a)<<endl;


    return 0;
}