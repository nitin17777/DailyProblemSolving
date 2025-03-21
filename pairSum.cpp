class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {

        for(int i=0; i<arr.size();i++)
        {
            for(int j = i+1; j<arr.size(),j++)
            {
                if( arr[i] + arr[j] == s)
                {
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(j); 
                    ans.push_back(temp);

                }
            }
        }
        
    }
    sort(ans.begin,ans.end())
    return ans;
}