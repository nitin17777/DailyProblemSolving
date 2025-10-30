#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> maxPossible(vector<ll> &arr)
{

    // choose an element from arr,move it to the end of the array

    // print the sum of k last elements of arr

    // now move the element back it's original position

    // k : {1,n}

    // for every k , we chose the element which should be moved so that value we print is max possible

    // calcualte the value for each k

    vector<ll> ans;

    // it should be like : k = 1 ->largest

    vector<ll> temp = arr;
    sort(temp.rbegin(), temp.rend());

    // if last k elements does not include the greatest number of array,push the greatest one , if is present, push the second highest one and continue doing until k  = n
}

int main()
{

    return 0;
}
