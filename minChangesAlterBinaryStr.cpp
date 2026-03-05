#include<bits/stdc++.h>
using namespace std;

int minOperations(string s)
{

    int n = s.size();
    int s0=0,s1=0;

    //Return the min ops to make s alternating

    //Changing the string to each pattern type
    for(int i = 0;i<n;i++)
    {
        if(i%2 == 0)
        {
            if(s[i] == '0')s1++;
            else s0++;
        }

        else
        {
            if(s[i] == '1')s1++;
            else s0++;
        }
    }
    return min(s0,s1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<minOperations("1111")<<endl;

    return 0;
}