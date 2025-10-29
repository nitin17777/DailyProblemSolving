#include<bits/stdc++.h>
using namespace std;

int ways(int d,vector<int>& heights)
{
    //find number of pairs 
    int n = heights.size();

    int count = 0;
    for(int i = 0; i < n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            if(abs(heights[i] - heights[j]) <= d)count++;
        }
    }
    return count*2;

}

int main()
{
    int n,d;
    cin>>n>>d;

    vector<int>heights(n);
    for(int i = 0;i < n;i++)cin>>heights[i];

    cout<<ways(d,heights)<<endl;

    return 0;
    
}
