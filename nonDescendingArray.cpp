#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll goodSubsets(vector<int> &a, vector<int> &b)
{

    // swap(ai,bi)for each i in the subset

    // a good subset is one in which after swapping,both arrays are sorted in non descending order

    // we have to calculate the numnber of good subsets
}

int main()
{

    vector<int> a = {2, 1, 4};
    vector<int> b = {1, 3, 2};

    cout << goodSubsets(a, b) << endl;

    return 0;
}
