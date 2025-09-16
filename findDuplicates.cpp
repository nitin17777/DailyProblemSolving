vector<int> findDuplicates(vector<int>& nums) {
    
            int n = nums.size();
    
    
    
    //storing all elements along with their frequencies
            unordered_map<int,int>freq;
            vector<int>arr[];
    
            for(int i = 0;i<n;i++)
            {
                freq[nums[i]]++;
            }
    
            for(auto &key : freq)
            {
                if(key.second >= 2)
                {
                    arr.push_back(key.first);
                }
            }
    
            return arr;
            
            
    
            
        }
    };