#include<iostream>
#include<vector>
using namespace std;


void heapify(vector<int>&arr, int i ,int n)
{
    int largest = i;
    int left = 2*i +1;
    int right = 2*i +2;

    if(left < n && arr[largest] <arr[left])
    {
        largest = left;
    }

    if(right < n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[largest] , arr[i]);
        heapify(arr,largest,n);

    }
}

vector<int>mergeHeaps(vector<int>& a , vector<int>&b , int n, int m)
{
    //step 1: merge both arrays into one

    vector<int>ans;
    for(auto i: a)
    {
        ans.push_back(i);
    }

    for(auto i:b)
    {
        ans.push_back(i);
    }

    //step 2: Build heap using merged array
    int size = ans.size();

    for(int i =size/2 - 1; i>=0; i--)
    {
        heapify(ans,i,size);
    }

    return ans;
}

int main()
{

    vector<int>arr1 = {10,5,6,2};
    vector<int>arr2 = {12,7,9};

    vector<int>an= mergeHeaps(arr1, arr2, 4, 3);

    for(auto a: an)
    {
        cout<<a<<" ";
    }
    cout<<endl;

    return 0;

}