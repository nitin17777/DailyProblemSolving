#include<bits/stdc++.h>
#define ll long long
using namespace std;

string multiply(string num1, string num2)
{

    if(num1 == "0" || num2 == "0")return "0";

    int n = num1.size(),m=num2.size();


    //Since max possible digits in the result can be n+m
    vector<int>ans(n+m,0);

    for(int i = n-1;i>=0;i--)
    {
        for(int j = m-1;j>=0;j--)
        {
            int mul = (num1[i]-'0') * (num2[j]-'0');

            int sum = mul + ans[i+j+1];

            // Storing the current digit.
            ans[i + j + 1] = sum % 10;

            // Carry is added to the previous position.
            ans[i + j] += sum / 10;
        }

    }

    string res;
    int i = 0;

    // Skip leading zeros.
    while (i < ans.size() && ans[i] == 0)i++;

    // Convert the digit array into the answer string.
    while (i < ans.size())res += ans[i++] + '0';

    return res;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<multiply("2","3")<<endl;
    
    return 0;
}