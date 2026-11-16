#include<bits/stdc++.h>
#define ll long long
using namespace std;

string digitSum(string s, int k)
{
    int n = s.size();

    //s>k -> round complete 

    //Each group is replaced by their sum

    //Divide s into consecutive groups of size k

    while(s.size() > k)
    {
        string temp = "";

        for(int i=0;i<s.size();i+=k)
        {
            int sum = 0;

            for(int j = i; j<min((int)s.size(),i+k); j++)sum+=s[j] - '0';

            temp += to_string(sum);
        }
        s=temp;
    }
    return s;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<digitSum("11111222223",3)<<endl;

    return 0;
}