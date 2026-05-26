#include<bits/stdc++.h>
#define ll long long
using namespace std;

int numberOfSpecialChars(string word)
{

    int n = word.size();

    int cnt = 0;
    set<int>st;

    for(auto &x:word)st.insert((int)x);

    for(auto&x:st)
    {
        if(x<=90)
        {
            if(st.find(x+32) != st.end())cnt++;
        }
    }
    return cnt;

}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<numberOfSpecialChars("aaAbcBC")<<endl;
    return 0;
}