#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - left;

    vector<int>leftArr(n1), rightArr(n2);

    //pushing all left elements into a new array called leftArr
    for(int i = 0 ; i < n1; i++)
    {
        leftArr[i] = arr[left+ i];
    }
    //pushing all right elements into a new array called rightArr
    for(int i = 0 ;i< n2; i++)
    {
        rightArr[i] = arr[mid+1+i];
    }

    int i = 0, j = 0,k = left;

    //now merging both the left and right array
    while(i < n1 && j <n2)
    {
        if(leftArr[i] < rightArr[j])
        {
            arr[k++] = leftArr[i++];
        }

        else
        {
            arr[k++] = rightArr[j++];
        }
    }

    //now copying remaining elements of lefArr if any
    while(i < n1)
    {
        arr[k++] = leftArr[i++];
    }

    while(j <n2)
    {
        arr[k++] =rightArr[j++];
    }

}

void mergeSort(vector<int>& arr, int left , int right)
{
    if(left <right)
    {
        int mid = left + (right - left)/ 2;

        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1, right);

        merge(arr,left,mid,right);
    }
}

void printArr(vector<int>& arr)
{
    for(auto num : arr)
    {
       cout<<num<<" ";
    }
    cout<<endl;
}


int main()
{
    vector<int>arr = {12,11,13,5,6,7};

    cout<<"Given Array : ";
    printArr(arr);

    mergeSort(arr,0,arr.size()- 1);

    cout<<"Sorted Array : ";
    printArr(arr);

    return 0;

}