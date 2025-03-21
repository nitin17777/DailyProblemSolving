#include<iostream>
#include<vector>
using namespace std;

//alter method

void rotate(vector<int> & arr)
{
    int n = arr.size();
    int last = arr[n-1];

    for( int i =n-1;i>0;i--)
    {
        arr[i] = arr[i-1];
        
    }
    arr[0] = last;
    
}


/*
void rotate(vector<int>&arr)
{

    vector<int>ans;
        
    int n = arr.size();
    
    
        ans.push_back(arr[n-1]);
        
        for(int i =0;i<n-1;i++)
        {
            ans.push_back(arr[i]);
        }
        arr = ans;

}
        */
            
int main()
{

    vector<int>neww = {1,2,3,4,5};

    rotate(neww);
    cout<<"Rotated Array: ";

    for(int i =0; i<neww.size(); i++)
    {
        
        cout<<neww[i]<<" ";
    }
    cout<<endl;

    return 0;

}