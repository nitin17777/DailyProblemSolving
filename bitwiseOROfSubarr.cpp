#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

    int subarrayBitwiseORs(vector<int>& arr)
    {
        //we have to return the unique bitwise OR of all the possible subarrays of given array
        
        //o(n^2): Not Optimal 
        //find all the possible subarrrays 
        //find bitwise or and store in a hashMap
        //then at last return all those elements in hash maps having  frequency greater than 0

        //Using set

        unordered_set<int>result, prev;

        for(int num : arr)
        {
            unordered_set<int>curr;

            curr.insert(num);

            for(int x: prev)
            {
                curr.insert(x|num); // storing or of current number and previously evaluated ORs
            } 

            for(int x:curr)//only unique elements would be there no matter what
            {
                result.insert(x);
            }

            prev = curr;
        }
        return result.size();  
    }


int main()
{

    vector<int>arr = {1,1,2};
    int ans= subarrayBitwiseORs(arr);
    cout<<ans<<endl;

    return 0;
    
}
