#include<iostream>
#include<vector>

using namespace std;

vector<int>findFactor(int n)
{
    vector<int>arr;


    for(int i =1; i<n; i++)
    {
        if(n%i == 0)
        {
            arr.push_back(i);
        }
    }

    return arr;
}

int kthFactor(int n,int k)
{
    vector<int>arr = findFactor(n);
    //now we have the array and it will obvioulsy sorted.So return the index

    if(arr.size() >= k)
    {
    return ans = arr[k-1];
    }
    else
    {
        return -1;

    }
}

int main()
{
    int n = 12;
    int k = 3;

    int ans = kthFactor(n,k);

    cout<<ans<<endl;

    return 0;

}