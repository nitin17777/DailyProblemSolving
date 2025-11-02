#include <bits/stdc++.h>
using namespace std;

vector<int> possible(vector<int> &arr)
{
    // f(c) = number of distinct elements in c
    //  c[i,j] = subarray of c bounded by positions i and j

    // we have an array b is such that : bi = f(a[1,i]) + f(a[2,i]) +...f(a[i,i])

    // find array a with elements 1<=ai<=n

    // Algo:

    /*f(l,r) = number of distinct elements in a[l...r]

    b[i] - b[i-1] will tell if we see any value at position i
    b[i] - b[i-1] == 0 => Repeated Value
    b[i] - b[i-1]  == 1 => Unique Value





    f(l, r) <= f(l,r+1) because new element introduced woud be either present earlier already or would be new , So : f(l, r+1) = f(l, r)  OR  f(l, r) + 1
    */
}

int main()
{
    vector<int> arr = {1, 3, 5};
    vector<int> ans = possible(arr);

    for (auto &an : ans)
    {
        cout << an << " ";
    }
    cout << endl;

    return 0;
}
