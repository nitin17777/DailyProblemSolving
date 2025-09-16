#include<iostream>
#include<vector>

using namespace std;

vector<int>good(int n)
{
    //if product of adjacent element is negative -> so every adjacent pair must have opposite sign

    //for all subarray with length atleast 2  has sum of elements in subarray as positive ->so positive number should be greater than the adjacent negative

    //an array is better if elements in one array are lexicographically smaller than elements of any other possible array
     //we have to answer the best possible array which follows these conditions

    vector<int>a(n);
    for(int i =0 ; i <n;i++)
    {
        if(i%2 ==0)
        a[i] =2;
    
        else
        {
            a[i] = -1;
        }
    }
    return a;
}

int main()
{

   /* int n = 2;

    vector<int>ans = good(n);

    for(auto&an: ans)
    {
        cout<<an<<" ";
    }
    cout<<endl;
*/
    int t;

    while(t--)
    {
        int  n;
        cin>>n;

        vector<int>ans = good(n);

        for(auto&an :ans)
        {
            cout<<an<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
