#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<int> p)
{

    int n = p.size();

    // choose a subarray p of length k and subtract 1 from every element in that array

    // after completing n operations our goal is to achieve a zero array
    // determine if it is possible to do so

    // for each k = 1,2....n, pick subarray of length k and then subtract 1 form all it's elements

    // after n steps array should become zero

    int l = 0;
    int r = n - 1;
    // 1 3 4 2
    for (int i = 1; i <= n; i++)
    {

        if (p[l] == i)
        {
            l++;
        }
        else if (p[r] == i)
        {
            r--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++)
        {
            cin >> p[i]; // 1 3 4 2
        }
        cout << ((isPossible(p)) ? "Yes" : "No") << endl;
    }
    return 0;
}
