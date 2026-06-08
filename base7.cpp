#include<bits/stdc++.h>
#define ll long long
using namespace std;

string convertToBase7(int num)
{

    if(num == 0)return "0";

    bool negative = num < 0;

    string ans = "";
    num = abs(num);

    while(num > 0)
    {
        ans += char('0' + (num%7));
        num /= 7;
    }


    reverse(ans.begin(),ans.end());
    if(negative)ans = '-' + ans;

    return ans;

}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   cout<<convertToBase7(100)<<endl;

    return 0;
}