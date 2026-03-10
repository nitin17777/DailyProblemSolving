#include<bits/stdc++.h>
using namespace std;

int solve(string&s)
{
    int n = s.size();
    //No two seats are occupied currently

    //Return the min total number of students possible that can more be seated

    //So basically we have to minimise the number of students can sit in a row while already fulfiling the requirements

    
   //So our idea should be : Every 3 consecutive zeros would fetech us one '1'

    s= '1' + s + '1'; //to bound the string 
    int ans = 0;
    
    for(int i = 1,l=0;i<=n;i++)
    {
        if(s[i] =='0')
        {
            //If already a student is there in previous cell, a new bloc of zeors will start from i
            if(s[i-1] =='1')
            {
                l = i;
            }

            if(s[i+1] == '1')
            {
                int c = (l == 1) + (i == n);
                
                ans+=(i-l+1+c)/3;
            }
        }

        //Student is already sitting
        else ans++;
    }
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
        int n;
        cin>>n;

        string s;
        cin>>s;

        cout<<solve(s)<<endl;
        
    }
    return 0;
}