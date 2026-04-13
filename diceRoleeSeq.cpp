#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<int>&a,int n)
{
    /*

    //Valid if: Both are not equal and x+y!=7

    Sequence if: All pairs of adjacent  elements lie on adjacent sides of the cube

    We can : Select any element and change it to any 1<= x <= 6

    Number of ops to make a dice roll sequence
        
    */

    int cnt = 0;
    for(int i=1;i<n;i++)
    {
        //increased i to avoid overlapping conflict
        if((a[i] == a[i-1] ) || a[i] + a[i-1] ==7)cnt++,i++;
    }
    return cnt;
}

      
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
        for(auto & x:a)cin>>x;

        cout<<solve(a,n)<<endl;
    }

    return 0;
}




