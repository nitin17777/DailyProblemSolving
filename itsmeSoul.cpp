#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        n++;
    
        string s;
        cin>>s;

        s = '0' + s;
        /*
        si=1 if integer i have been given to him else si=0

        Game will go up for 1000 turns and both players play in alternating turns 

        Score = max(s) - min(s) ,s= set of integrs he owns

        S wants to maximise his score and Kal wants ot minimise soul's score 
         
        find soul's final score


        Soul plays first
        They should give atleast one of their owned integer in their respective turn

        */

        vector<int>a;
        for(int i=n;i>0;i--)
        {
            if(s[i] =='1')a.push_back(i);
        }

        int m = a.size();

        if(m==1)
        {
            cout<<0<<'\n';
            continue;
        }

        if(m==2)
        {
            cout<<1<<'\n';
            continue;
        }
        cout<<a[0]-a[a.size()-1]<<'\n';
    }

    return 0;
}