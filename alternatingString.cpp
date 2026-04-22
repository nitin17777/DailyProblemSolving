#include<bits/stdc++.h>
#define ll long long
using namespace std;


bool solve(string&s)
{
    int n = s.size();

    /*

    Choose a substring and invert all its letters and then reverse the string 
    
    Determine if we can obtain any alternating string from string s

         
    */

}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        string n;
        cin>>n;

        cout<<(solve(n)?"YES" : "NO")<<endl;    
    }

    return 0;
}