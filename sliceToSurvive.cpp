#include <bits/stdc++.h>
using namespace std;
#define ll long long 


/*
f(x) = number of turns needed to reduce 1*x grid to 1*1, when fds moves first each turn 

Recurrence
f(1) = 0
f(x) = 1+ f(ceil(x/2));


*/

//equals ceil(log2(x))
ll f(ll x)
{
    if(x<=1)return 0;

    return (ll)ceil(log2((double)x));
}



int minTurns(int n, int m, int a, int b)
{

    //Fds monsters starts at cell (a,b) where rows are numbered 1 to nand cols 1 to m

    /*
    In each turn:  

    mouf wants to minimise the number of turn,while fds wnats to maximise them 

    Return the number of turns this duel will last


    To minimise turns, Mouf should always cut so that the remaining dimension is as small as possible 
    */

    ll ans = LLONG_MAX;

     // --- Case 1: Keep top part → rows become a
    ans = min(ans, f(a) + f(m));

    // --- Case 2: Keep bottom part → rows become n - a + 1
    ans = min(ans, f(n - a + 1) + f(m));

    // --- Case 3: Keep left part → columns become b
    ans = min(ans, f(n) + f(b));

    // --- Case 4: Keep right part → columns become m - b + 1
    ans = min(ans, f(n) + f(m - b + 1));


    return 1+ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, a, b;
        cin >> n >> m >> a >> b;

        cout << minTurns(n, m, a, b)<<endl;
    }
    return 0;
}
