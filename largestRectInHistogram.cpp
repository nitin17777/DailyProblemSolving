#include<bits/stdc++.h>
using namespace std;

vector<int>nextSmallerElement(vector<int>&arr,int n)
{
    stack<int> s; //initiallised a stack
    s.push(-1); //initiallised stack with -1 to handle edge cases
    vector<int>ans(n); // to store next smaller elements


    //Traversing from right to left
    for(int i = n-1; i>=0; i--)
    {
        int curr= arr[i];

        //Now popping current element until smaller element is found
        while(s.top()!= -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();

        s.push(i);
    }
    return ans;
}


 vector<int>prevSmallerElement(vector<int>arr,int n)
{
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);

    for(int i = 0; i<n;  i++)
    {
        int curr= arr[i];
        while(s.top()!= -1 && arr[s.top()] >= curr)
        {
            s.pop();

        }

        ans[i] = s.top();
        s.push(i);
    }

    return ans;
    
 }

//function to calculate largest rect area now
int largestRectArea(vector<int>&heights)
{
    int n = heights.size();

    vector<int>next(n);
    next = nextSmallerElement(heights,n);


    vector<int>prev(n);
    prev = prevSmallerElement(heights,n);
    
    int area = INT_MIN;

    for(int i = 0; i<n; i++)
    {
        int l = heights[i]; //height of current bar

// if there is no smaller element on right consider the end of array
        if(next[i] == -1)
        {
            next[i]= n;
        }

        int b = next[i] - prev[i]- 1; //width of rectangle

        int newArea = l*b;

        area = max(area,newArea);
    }

    return area;
}


int main()
{

    vector<int>heights = {3,4,2,6,7,9};

    int maxArea = largestRectArea(heights);

    cout<<maxArea<<endl;




    return 0;

}