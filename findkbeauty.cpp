#include<bits/stdc++.h>
#define ll long long
using namespace std;

int divisorSubstrings(int num, int k) {
        
string s = to_string(num);

int cnt = 0;

for(int i = 0; i <= s.size()-k; i++)
{
    // Take substring of length k
    string sub = s.substr(i,k);
    
    // Convert into integer
    int val = stoi(sub);
    
    // 0 cannot divide anything
    if(val != 0 && num % val == 0)
    {
        cnt++;
    }
}

return cnt;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<divisorSubstrings(240,2)<<endl;


    return 0;
}




