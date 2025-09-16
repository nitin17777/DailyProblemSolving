#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

    int largestPerimeter(vector<int>& arr)
    {
        //we have to find the largest possible perimeter of triangle possible

        //for a valid triangle: a + b >c(sum of 2 sides must be greater than the 3rd side)

        sort(arr.begin(),arr.end(),greater<int>()); //descending sort , so as to avoid checking much triplets
        
        for(int i = 0;i<arr.size()-2;i++)
        {
            if(arr[i] < arr[i+1] + arr[i+2])
            {
                
                return arr[i] + arr[i+1] + arr[i+2];
            }//and as soon as this condition satisfies,the loop will end

        }
        return 0;
    }


int main()
{
    vector<int>arr = {1,2,1,10};
    int ans = largestPerimeter(arr);

    cout<<ans<<endl;

    return 0;
    
}
