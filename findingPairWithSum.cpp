#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class FindSumPairs
{
    public:
    vector<int>n1,n2;

    unordered_map<int,int>freq;

    FindSumPairs(vector<int>nums1,vector<int>nums2)
    {
        n1 = nums1;
        n2 = nums2;
        
        //making a hash map for frequency mapping of each number in nums2
        for(int num: n2)
        {
            freq[num]++;//increasing count of this number in the map

        }
    }

    //It adds the value to the element at index of nums2
    void add(int index,int val)
    {
    
        //decrease the frequency of old value at index in n2 as after adding value it's value will be changed
        freq[n2[index]]--;

        //if frequency becomes 0, we erase it from the map for cleaner hash map
        if(freq[n2[index]] == 0)
        {
            freq.erase(n2[index]);
        }

        //now actually updating the value of nums[index]
        n2[index] += val;

        //and now increase the frequency of new value
        freq[n2[index]]++;
    }

//returns count of pairs of i,j : n1[i] + n2[j] == tot
    int count(int tot)
    {
        int cnt = 0;
        for(int num: n1)
        {
            int target = tot-num;


            //now checking if target exists in the freq map of nums2
            if(freq.find(target) != freq.end())//freq.end() means the key was not found
            {
                cnt+=freq[target];
            }
        }
        return cnt;
    }
};

/*

class FindSumPairs
{
    public:
    vector<int>n1,n2;

//Constructor to initiallise nums1 and nums2
FindSumPairs(vector<int>& nums1, vector<int>& nums2)
{
    n1 = nums1;
    n2 = nums2;
     
}
    
    void add(int index, int val) {

        n2[index]+= val; 
        
    }
    
    int count(int tot) {

        int countt = 0;
        for(int i = 0;i<n1.size();i++)
        {
            for(int j = 0; j <n2.size();j++)
            {
                if(n1[i] + n2[j] == tot)
                countt++;
            }
        }

        return countt;

        
    }
};
*/

int main()
{

    vector<int>nums1 = {1,2,3};
    vector<int>nums2 = {3,4};



    //instantiate the object
    FindSumPairs *obj = new FindSumPairs(nums1,nums2);

    cout<<"Count of pairs with sum 5: "<<obj->count(5)<<endl;

    obj->add(1,1); 

    cout<<"Count of pairs with sum 6: "<<obj->count(6)<<endl;


    delete obj;


    return 0;
    
}
