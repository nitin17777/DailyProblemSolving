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

        string s;
        cin>>s;
        
        // Choose palindrome substring of atleast length = 2, and delete one char from that sub

        // Find min possible length of s 

        int k =0;
        for(int i =1;i<n;i++)
        {
            if(s[i]!=s[i-1])k++;
        }
        cout<<(k==1?2:1)<<'\n';
    }

    return 0;
}