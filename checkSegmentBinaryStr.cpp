#include<bits/stdc++.h>
using namespace std;

bool checkOnesSegment(string s)
{

    int n = s.size();

    //Check if we have only one contiguous segment of ones or not

    int cnt = 0;
    if(s[0] == '1')cnt++;

    for(int i =1;i<n;i++)
    {
        if(s[i] == '1')
        {
            if(s[i-1] != '1')cnt++;
        }
    }

    return cnt<=1;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<(checkOnesSegment("1")?"true":"false")<<endl;
    return 0;
}