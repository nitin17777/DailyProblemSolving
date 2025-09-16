#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>&height)
{

    int left = 0 ; 
    int right = height.size() -1;
    int maxWater = 0;

    while(left < right)
    {
        int ht = min(height[right] , height[left]);
        int width = right - left;
        int area = ht * width;

        maxWater = max(maxWater,area);

        if(height[left] < height[right])
        {
            left++;
        }
        else
        right--;

    }

    return maxWater;

}

/*
int maxArea(vector<int>&height)
{
    int n = height.size();

    //two vertical lines are there such that two endpoints of ith lines are (i,0) and (i,height[i])

    //we have to find two lines that together with x axis form a container such that container contains the most water....Return the max amount of water container can store

    //so basically we have to find the lines such that height * (index diff) is maximum

    int maxx = 0;

    for(int i = 0;i <height.size();i++)
    {
        
        for(int j = 1; j <height.size(); j++)
        {

            int count = min(height[i] , height[j]) * abs(i-j);
            maxx = max(count,maxx);

        }
    }
    return maxx;


}
*/


int main()
{

    vector<int>height = {1,8,6,2,5,4,8,3,7};

    int ans = maxArea(height);

    cout<<ans<<endl;

    return 0;

}