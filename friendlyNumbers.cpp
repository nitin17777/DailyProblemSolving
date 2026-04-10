#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(int x) {
    int count = 0;

    for (int i = x; i <= x + 83; i++) {
        int sum = 0, temp = i;

        while (temp) {
            sum += temp % 10;
            temp /= 10;
        }

        if (i - sum == x) count++;
    }

    return count;
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

    cout<<solve(n)<<endl;}

    return 0;
}