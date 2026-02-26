#include <bits/stdc++.h>
using namespace std;
#define ll long long

int numSteps(string s)
{

    // Directly working with bits here in this method, instead of first converting and then checking

    int steps = 0;

    while (s != "1")
    {

        // divide by 2 in this case
        if (s.back() == '0')
            s.pop_back();

        else // add 1
        {
            int i = s.size() - 1;

            while (i >= 0 && s[i] == '1')
            {
                s[i] = '0';
                i--;
            }

            if (i < 0)
            {
                s = '1' + s;
            }
            else
            {
                s[i] = '1';
            }
        }
        steps++;
    }
    return steps;
}

/*

//No compatible for bigger inputs

int numSteps(string s)
{
    int n = s.size();
    ll num=0;

    int k = 0;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i] == '1')
        {
            num +=(1LL<<k);
        }
        k++;
    }
    int ans=0;

    while(num>1)
    {
        if(num%2 == 0)
        {
            num/=2;
        }
        else num++;

        ans++;
    }
    return ans;
}
    */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << numSteps("1101") << endl;
    return 0;
}