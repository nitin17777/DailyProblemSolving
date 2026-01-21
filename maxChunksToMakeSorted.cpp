#include <bits/stdc++.h>
using namespace std;

int maxChunksToSorted(vector<int> &arr)
{
    int chunks = 0;
    int maxSoFar = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        maxSoFar = max(maxSoFar, arr[i]);

        if (maxSoFar == i)
            chunks++;
    }
    return chunks;
}

/*
int maxChunksToSorted(vector<int>& arr)
{

    int n = arr.size();

    vector<int>temp = arr;

    if (temp == arr)return 0;

    reverse(temp.begin(),temp.end());

    if(arr == temp)return 1;

    int len = 1;
    for(int i = 1;i<n;i++)
    {
        if(arr[i] < arr[i-1])
        {
            len++;
        }
    }

    return n - len;
}*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> a = {4, 3, 2, 1, 0};
    cout << maxChunksToSorted(a) << endl;

    return 0;
}