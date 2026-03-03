#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(const string& s,ll x,ll k)
{
    ll n = s.size();
    
    //Whenever robot reaches point 0, the counter executed commands are reset

    //Calculate how many times the robot will enter the point 0 during next k seconds

    ll remTime = k;
    ll currPos = x;
    ll ans =0;

    for(ll i=0;i<n && remTime>0;i++)
    {
        if(s[i] == 'L')currPos--;
        else currPos++;

        //One second used already
        remTime--;

        if(currPos == 0)
        {
            ans = 1;//Reaching 0 for the first time
            break;
        }
    }

    //If robot never reaches 0 is first place, it will never reach 0 in future cycles as well,as the motion is repetitive
    if(ans == 0)return 0;


    //As robot is at position 0 rn, we check how long it takes to return to 0 again starting from 0 

    currPos=0;
    ll cycleLen = -1;

    for(ll i =0;i<n;i++)
    {
        if(s[i] == 'L')currPos--;
        else currPos++;

        if(currPos == 0)
        {
            cycleLen = i+1;
            break;
        }
    }

    if(cycleLen == -1)return ans;

    ans += remTime/cycleLen;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        ll n,x,k;
        cin>>n>>x>>k;

        string s;
        cin>>s;

        cout<<solve(s,x,k)<<endl;
    }
    return 0;
}