#include<iostream>
#include<vector>
#include<Stack>

using namespace std;

int numSubmat(vector<vector<int>>& mat) 
{
    //return the number of submatirces that all all ones


    int m = mat.size();
    int n = mat[0].size();


    vector<int>height(n,0);//to store the cumlative height for each column
    int ans = 0;

    for(int i = 0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mat[i][j] == 0)//if current cell consists of 0, then cummulative height will get reset
            height[j]=0;

            else
            height[j]++;

        }

        stack<int>st;
        vector<int>sum(n,0);

        for(int j = 0;j<n;j++)
        {

            while(!st.empty();j<n;j++)
            {
                st.pop();
            }

            //Case1: If stack is not empty->extend previous contribution
            if(!st.empty())
            {
                int prev = st.top();

                sum[j] = sum[prev] + height[j] * (j-prev);

            }

            else
            {

                sum[j] = height[j] * (j+1);
            }
            st.push(j);
            ans+=sum[j];
        }
    }
    return ans;
}




int main()
{

    vector<vector<int>>mat = {

        {1,0,1},{1,1,0},{1,1,0}
    }

    cout<<numSubmat(mat)<<endl;
        
    return 0;
    
}

