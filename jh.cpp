#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector<vector<int>> result;
            int n = nums.size();
    
            if (n < 4) {
                return result;
            }
    
            sort(nums.begin(), nums.end());
    
            for (int i = 0; i < n - 3; i++) {
                if (i > 0 && nums[i] == nums[i - 1]) { // Skip duplicate 'i'
                    continue;
                }
                for (int j = i + 1; j < n - 2; j++) {
                    if (j > i + 1 && nums[j] == nums[j - 1]) { // Skip duplicate 'j'
                        continue;
                    }
    
                    int left = j + 1;
                    int right = n - 1;
    
                    while (left < right) {
                        long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
    
                        if (sum == target) {
                            result.push_back({nums[i], nums[j], nums[left], nums[right]});
                            left++;  // Move pointers (no duplicate handling needed here)
                            right--;
                        } else if (sum < target) {
                            left++;
                        } else {
                            right--;
                        }
                    }
                }
            }
            return result;
        }


        int main()
        {
    
            vector<int>arr = {-3,-2,-1,0,0,1,2,3};
            int tr=0;
    
    
            vector<vector<int>>answer = fourSum(arr,tr);
    
            for (auto& quad : answer) {
            for (int num : quad) {
                cout << num << " ";
            }
            cout << endl;
        }
    
        return 0;
    }