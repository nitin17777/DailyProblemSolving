#include<bits/stdc++.h>
#define ll long long
using namespace std;

int maxNumberOfBalloons(string text)
{

    vector<int>cnt(26,0);

    for(auto&x:text)
    {
        cnt[x-'a']++;
    }


    return min({
            cnt['b' - 'a'],
            cnt['a' - 'a'],
            cnt['l' - 'a'] / 2,
            cnt['o' - 'a'] / 2,
            cnt['n' - 'a']
        });
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<maxNumberOfBalloons("nlaebolko")<<'\n';

    return 0;
}