#include<iostream>
#include<vector>

using namespace std;

    int candy(vector<int>& ratings)
    {
        //each child must have atleast one candy

        //children with higher rating gets more candises than neighbours

        //we have to return the minimum number of candies to distribute candies to the children
        int n = ratings.size();
        vector<int>candies(n,1);

        //left to right
        for(int i = 1; i < n; i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                candies[i] = candies[i-1] + 1;
            }
        }

        //right to left
        for(int i = n-2; i>=0 ;i --)
        {
            if(ratings[i] > ratings[i+1])
            {
                candies[i] = max(candies[i], candies[i+1]+1);
            }
        }
        int totalCandies= 0; 
        for(int c : candies)
        {
        totalCandies += c;
        }

        return totalCandies;
    }

int main()
{
    vector<int>ratings = {1,0,2};
    int candies = candy(ratings);

    cout<< candies<< endl;

    return 0;
}