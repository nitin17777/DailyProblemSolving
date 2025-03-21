#include<iostream>
#include<vector>

using namespace std;

int findDup(vector<int> &arr)

{
    int ans = 0 ;

    //XOR all elements in array
    for(int i = 0; i<arr.size();i++)
    {
        ans = ans^arr[i];

    }

    //XOR with numbers from 1 to n-1
    for(int i = 1; i<arr.size();i++)
    {
        ans = ans^i;
    }
    return ans;
}

int main()
{

    vector<int> arr = {1,1,4,3,2};
    int c = findDup(arr); 
    cout<< c <<endl;

    return 0;
}