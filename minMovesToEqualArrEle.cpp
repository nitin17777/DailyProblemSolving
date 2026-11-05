#include<bits/stdc++.h>
#define ll long long
using namespace std;


int minMoves(vector<int>& a)
{

    int n = a.size();

    //Min moves to make all array elements equal
    //In one move increment n-1 number of elements of array by 1 == decreasing that one element in each move 


    int mn = *min_element(a.begin(),a.end());

    int ans=0;

    for(int x:nums)ans+=x-mn;

    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>a = {1,2,3};
    cout<<minMoves(a)<<endl;

    return 0;
}