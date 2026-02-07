#include<bits/stdc++.h>
using namespace std;

int minimumDeletions(string s)
{
    int n = s.size();

    //Return the min number of deletions needed to make s balanced

    //Balanced if a is always before and no a can be after b

    int b = 0,del = 0;

    for(char c:s)
    {
        if(c=='b')b++;
        else del = min(b,del+1);
    }
    return del;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<minimumDeletions("aababbab")<<endl;
    return 0;
}