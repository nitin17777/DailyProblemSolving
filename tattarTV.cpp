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
        int n,k;
        cin>>n>>k;

        string s;
        cin>>s;

        //In one move he can choose i and invert chars at i and i+k
        // Determine if he we an make the string equal to 0

        string t(n,'0');
        bool possible = true;
        for(int i = 0;i<n;i++)
        {

            if(s[i] == '1')
            {
                // Last chance to fix this '1'
                if(i + k >= n)
                {
                    possible = false;
                    break;
                }

                // Invert both positions
                s[i] ^= 1;
                s[i + k] ^= 1;
            }
        }   

        cout << (possible ? "Yes" : "No") << '\n';
        }
    return 0;
}