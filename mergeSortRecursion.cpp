#include<iostream>
using namespace std;

void merge(int *arr ,int s,int e)

{
    int mid = s+(e-s)/2;

    int len1= mid - s +1;
    int len2 = e-mid;
      //creating temporary arrays to hold right and left part
      int *first = new int[len1];
      int *second = new int[len2];


      //copying the values of old array to new formed array


      for(int i=0;i<len1;i++) //for left part 
      {
        first[i] = arr[s+i];

      }

      for(int i = 0;i<len2;i++)
      {
        second[i] = arr[mid+1+i];

      }


      //now merging both arrays back to return the sorted merged array

      int index1= 0 ,index2 = 0, mainArrayIndex = s;

      while(index1 < len1 && index2 < len2)
      {
        if(first[index1] < second[index2])
        {
            arr[mainArrayIndex++] =first[index1++];

        }

        else
        {
            arr[mainArrayIndex++] = second[index2++];

        }
      }// If there are remaining elements in first array


    while (index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    // If there are remaining elements in second array
    while (index2 < len2) {
        arr[mainArrayIndex++] = second[index2++];
    }

    // Clean up dynamic memory
    delete[] first;
    delete[] second;

}

void mergeSort(int *arr,int s,int e)
{
    //base case
    if(s>=e)
    {
        return;
    }

    int mid = s + (e-s)/2;


    //sorting the left part 
    mergeSort(arr,s,mid);


    //sorting the right part
    mergeSort(arr,mid+1,e);



// we merged both the arrays after sorting them to form a new sorted array
    merge(arr,s,e);
}


int main()
{


    int arr[6] = {2,5,1,6,9,8};

    int n =  6;

    mergeSort(arr,0,n-1);

    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";

    }
    cout<<endl;
    return 0;

}