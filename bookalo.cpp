#include<iostream>
#include<vector>
using namespace std;  

//function to check if mid can be the answer or not
bool isPossible(vector<int> arr , int n, int m, int mid)

{//[10,20,30,40,50]
    int studentCount = 1;
    int pageSum = 0;

    for(int i =0; i < n; i++ )
    if(arr[i] > mid)
    //mid can't be the solution in this case
    {
        return false;

    }

    {
        if(pageSum +arr[i]<=mid)
        {
            pageSum +=arr[i];

        }
        else
        {
            studentCount++;

            if (studentCount >= m || arr[i] > mid)
            {
                return false;
                
            } 
            pageSum = arr[i];

        }

    }
    return true;

}

int allo(vector<int> arr , int n,int m)
{
//end case when no.of books smaller than no. of students
    if(n<m)
    {
        return -1;

    }
//initiallising sum and start
int s =0 ;
int sum = 0;


for(int i = 0; i<n; i++)
{
    sum +=arr[i];

}
int e = sum;

int ans = -1;

int mid = s +(e-s)/2;


while(s<=e)

{

    if(isPossible(arr,n,m,mid))
    {
        ans = mid;
        e = mid-1;
         
    }

    else
    {
        s = mid+1;

    }
    mid = s+(e-s)/2;


}

return ans;


}

