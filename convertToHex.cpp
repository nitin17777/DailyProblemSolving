#include<bits/stdc++.h>
#define ll long long
using namespace std;


string toHex(int num) {

        if(num == 0)
            return "0";

        string hex = "0123456789abcdef";

        unsigned int n = num;

        string ans = "";

        while(n > 0)
        {
            int rem = n % 16;

            ans += hex[rem];

            n /= 16;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<toHex(26)<<endl;
    return 0;
}




