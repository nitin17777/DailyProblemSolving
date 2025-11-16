#include <bits/stdc++.h>
using namespace std;

int ans(string &s)
{
    /*

    < => Leftward Current
    > => RightWard Current
    * => No Current

    //Each move takes one minutes
    //Return the max time monocarp can sail along the river before endng up on the shore

    //if he can sail infinitely, return -1;


    if there is something like : ><,answer will be -1

    if string is like : <<<<.....<<>>..>>>> => max number of ether arrows would be the answer



    */
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int s;
        cin >> s;

        cout << ans(s) << endl;
    }
    return 0;
}
