#include<iostream>
#include<vector>
using namespace std;

int minCost(vector<int>&arr)
{
    //awesome if : If i odd -> bi < b i+1 holds
                // If i is even -> bi > bi+1 holds
                //elements at even position are always greater than elements at odd positions

                 //b1<b2>b3<b4 simply

    //we can do 2 opertaions:1=>select i and do ai = max(a1,a2,...ai)
                          // 2=>or select i and decrease ai by 1

    //Determine min number of times we need to do operation 2 to make given array awesome
    int n = arr.size();
    int cost = 0;


    for(int i = 0;i+1 <n;i++)
    {
        if(i%2 ==0)
        {
            if(arr[i] > arr[i+1])
            {
                int diff = arr[i] -arr[i+1] +1;
                cost+=diff;
              arr[i] -= diff; // decrease current to make it smaller
            }
        } 
        
        else 
        { // i is odd => need a[i] > a[i+1]
            if (arr[i] <= arr[i+1]) {
                int diff = arr[i+1] - arr[i] + 1;
                cost += diff;
                arr[i+1] -= diff; // decrease next to make it smaller
            }
        }
    }

    return cost;
}


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int>arr(n);
        for(int i =0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<minCost(arr)<<endl;
    }
        return 0; 
}
