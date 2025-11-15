#include <bits/stdc++.h>
using namespace std;

int ans(vector<int> &s)
{
    /*

    < => Leftward Current
    > => RightWard Current
    * => No Current

    //Each move takes one minutes
    //Return the max time monocarp can sail along the river before endng up on the shore

    //if he can sail infinitely, return -1;

    */

    // if both types of arrow are there, return -1,
    // else

    // He must move to left or right, even if no current is there

    // if
    if (s.size() == 1 && s[0] == '*')
        return 1;
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
