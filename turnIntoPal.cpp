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
        char c;  

        cin>>n;
        cin>>c;

        string s;
        cin>>s;

        //Min ops to turn it into palindrome

        int left =0,right=n-1;

        int ans = 0;
        while(left<right)
        {
            if(s[left]!=s[right])
            {
                if(s[left]==c || s[right]==c)ans+=1;
                else ans+=2;
            }

            left++;
            right--;
        }
        cout<< ans << '\n';    
    }
    return 0;
}