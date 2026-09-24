#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll trailingZero(ll x)
{
    ll cnt=0;

    while(x%10==0)
    {
        cnt++;
        x/=10;
    }
    return cnt;
}

string solve(vector<ll>&a,int n,int m,ll totalDigits)
{
    /*

    Anna makes the first move

    Anna choses any element ai and reverse the sequence of this element'S digit
    Sasha concatenates and removes two numbers and insert them back in any order


    Game ends when after Anna's move exactly one number is left in the list : and if this number is not less than 10^m -> Sasha wins, else Anna
 

    When only one element is left after Anna and this number is not less than 10^m ->  Sasha wins
    
    */

    // Final digit <= finals -> Anna wins, else sasha wins
    vector<ll>zeros;
    for(auto&x:a)zeros.push_back(trailingZero(x));
    sort(zeros.rbegin(),zeros.rend());

    ll removed = 0;

    //Since anna will be choosing numbers alternatively
    for(int i=0;i<n;i+=2)
    {
        removed+=zeros[i];
    }

    totalDigits -= removed;

    if(totalDigits-1 >= m)return "Sasha";
    return "Anna";
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,m;
        cin>>n>>m;

        vector<ll>a(n);

        ll totalDigits =0;
        for(auto& x:a)
        {
            cin>>x;
            totalDigits += to_string(x).size();
        }
        cout<<solve(a,n,m,totalDigits)<<'\n';
    }

    return 0;
}