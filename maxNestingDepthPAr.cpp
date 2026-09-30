#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> maxDepthAfterSplit(string seq)
{
    int n=seq.size();


    /*

    VPS is: It consists of ( or )

    Split it into two disjoint subsequence A and B

    choose A and B such that max(depth(a),depth(b)) is minimum
    
    */
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<maxDepthAfterSplit("(()())")<<endl;

    return 0;
}