#include<bits/stdc++.h>
#define ll long long
using namespace std;

int findLUSlength(string a, string b)
{
    if (a == b) return -1;
    
    return max(a.size(), b.size());
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<findLUSlength("aba","cdc")<<endl;

    return 0;
}