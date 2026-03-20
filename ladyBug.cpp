#include <bits/stdc++.h>
using namespace std;

bool isPos(string a, string b)
{

    /*

    Choose index : 2<=i<=n

    In one operation : swap(ai, bi-1)
                     : swap(bi,ai-1)

                     
    Password is considered cracked if she can ensure that first string consists of only zeros
                    
    Determine if she will be able to save Dasha

    */

    int n = a.size();
    int cnt1 = 0, cnt2 = 0;

    //We can preserve the sequence of 0 and 1 provided that their qunatities within zig zag are preserved

    //Yes : if number of 0 is at least ceil(n/2)in frist zig zag and floor(n/2)in the second one

    // a0,b1,a2,b3....
    // b0,a1,b2,a3


    for(int i = 0;i<n;i++)
    {
        if(i&1)//odd
        {
            cnt2 += a[i] == '0';
            cnt1 += b[i] == '0';
        }

        else//even
        {
            cnt1 += a[i] == '0';
            cnt2 += b[i] == '0';
        }
    }

    return (cnt1 >= (n+1)/2)  && (cnt2 >= n/2);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string a, b;
        cin >> a >> b;

        cout << (isPos(a, b) ? "Yes" : "No") << endl;
    }
    return 0;
}
