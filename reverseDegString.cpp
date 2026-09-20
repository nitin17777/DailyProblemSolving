#include<bits/stdc++.h>
#define ll long long
using namespace std;

int reverseDegree(string s)
{

    int n = s.size();

    int ans = 0;

    for(int i=0;i<n;i++)
    {
        ans+=(i+1)*('z' -s[i]+1);
    }
    return ans;
}


      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<reverseDegree("abc")<<endl;

    return 0;
}