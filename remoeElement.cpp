#include<iostream>
#include<vector>
using namespace std;


int removeElement(vector<int>& nums, int val) {

        //we have to remove all occurences of val and return the number of elements

        int n = nums.size();

        int  newL = 0;

        for(int i = 0;i <n; i++)
        {
            if(nums[i] != val)
            {
                nums[newL] = nums[i]; //for i = 0; if value at i= 0 is not same as val , then nums[0] = nums[i =0] and newl++
                newL++; //and the number of times newl increased would tell the size of array
                
            }

        }
        return newL;
        
    }


int main()
{

    vector<int> arr = {1,2,2,2,3,3}; //6


    int gg = removeElement(arr,4);

    cout<<gg<<endl;




    return 0;

}