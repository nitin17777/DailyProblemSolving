#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool uniformArray(vector<int>& a)
{
    int n = a.size();


    //we have to construct array whose elements are either all odd or all even

    /*
    ee o
    eo o
    oo e 

    either b[i] = a[i] or b[i] = a[j]-a[i];s
    
    
    */

    int even = 0,odd = 0;
    for(auto& x:a)if(x%2==0)even++;
    else odd++;

    // 4 5 6 7 8 9 -> even = 3, odd =3
    //  even -> 4, 
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
    
    }

    return 0;
}