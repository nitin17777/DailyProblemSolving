#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maximumGap(vector<int>& nums) 
{
        int sizee = nums.size();

    
        int maxDiff = 0;
    
            if(sizee < 2)
            {
                return 0;

            }
            sort(nums.begin(),nums.end());//sorted the array first


        //find the difference between two successive numbers now and then store it in the maxDiff

        for(int i = 0; i<sizee-1; i++)
        {
            int dif = nums[i+1] - nums[i];

            if(dif>maxDiff)
            {

                maxDiff = dif;
            }          
        }
        return maxDiff;     

        }

int main()
{

    vector<int>arr = {3,5,6,7,11};

    int ans = maximumGap(arr);

    cout<<"Maximum Gap is: "<<ans<<endl;

    return 0;

}
