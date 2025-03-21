#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//in the given array, starting from 1st, we have to find the first smaller number that number and if no such number is found return -1;

/*
vector<int>nextSmall(vector<int>&arr)
{

    vector<int>ans;

    int n = arr.size();
    int start = 0;

    for(int i = 1; i<n; i++)
    {
        if(arr[start]>arr[i])
        {
            ans.push_back(arr[i]);
            start++;
        }
        
        else
        {
            ans.push_back(-1);
        }
    }
    return ans;
}

int main()
{

    vector<int>arr = {5,3,2,6,7,1};
    vector<int>anss = nextSmall(arr);


    for(int i = 0; i<anss.size(); i++)
    {
        cout<<anss[i]<<" ";
    }
    cout<<endl;
 
    return 0;

}

*/

//we will do this question using stack now


vector<int> nextSmall(vector<int>& arr ,int n )
{
    stack<int>s;

    s.push(-1);

    vector<int>ans(n);


    for(int i = n-1; i>=0; i--)
    {

        int curr = arr[i];
        while(s.top() >= curr)
        {
            s.pop();
        }
        // and if we are here out of the loop, we are sure that s.top >= curr

        ans[i] = s.top();
        s.push(curr);

    }
    return ans;

}


int main() {
    vector<int> arr = {5, 3, 2, 6, 7, 1};
    int n = arr.size();

    vector<int> anss = nextSmall(arr, n);

    // Printing the result
    for (int i = 0; i < anss.size(); i++) {
        cout << anss[i] << " ";
    }
    cout << endl;

    return 0;
}