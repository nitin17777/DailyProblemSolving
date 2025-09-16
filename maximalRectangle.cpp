#include<iostream>
#include<vector>
#include<stack>
using namespace std;



int largestRectangleArea(vector<int>&heights)
{
    stack<int>st;
    heights.push_back(0);
    int maxArea =0;

    for(int i =0;i<heights.size();i++)
    {
        while(!st.empty() &&heights[st.top()] > heights[i])
        {
            int h = heights[st.top()];
            st.pop();

            int left = st.empty() ? -1:st.top();

            int width=i-left-1;
            maxArea = max(maxArea,h*width);

        }
        st.push(i);

    }

    heights.pop_back();
    return maxArea;

}


int maximalRectangle(vector<vector<char>>& matrix)
{
    if(matrix.empty())return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();

    int maxArea = 0;

    vector<int>heights(cols,0);

    for(int i = 0 ;i<rows;i++)
    {
        for(int j =0;j<cols;j++)
        {
            if(matrix[i][j] == '1')
            heights[j]+=1;

            else
            heights[j]=0;
        }
        maxArea = max(maxArea,largestRectangleArea(heights));
    }

    return maxArea;
}

int main()
{
    vector<vector<char>>matrix = 
    {
        {'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}
    };

    cout<<maximalRectangle(matrix);

    return 0;
}