#include<bits/stdc++.h>
using namespace std;
const double EPS = 1e-6;

bool solve(vector<double>nums)
{
    int n = nums.size();
    
    //When only one number remains, check if it's close to 24
    if(n==1)return fabs(nums[0] - 24);

    //Try every possible pair of numbers
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)continue;//to avoid picking same number twice

            vector<double>next;
            for(int k=0;k<n;k++)
            {
                if(k!=i && k!=j)
                next.push_back(nums[k]);

            }

            //Trying all arithmetic ops on nums[i] and nums[j]
            for(int op=0;op<4;op++)
            {
                if(op<2 && i>j) continue;

                
                    if(op == 0)
                    {
                        next.push_back(nums[i] + nums[j]);
                    }
                    else if(op == 1)
                    {
                        next.push_back(nums[i] - nums[j]);
                    }
                    else if(op == 2)
                    {
                        next.push_back(nums[i] * nums[j]);

                    }

                    else if(op == 3)
                    {
                        if(fabs(nums[j] > EPS))
                        {
                            next.push_back(nums[i] / nums[j]);

                        }
                        else 
                        {
                            continue;
                        }

                    }

                    if(solve(next))
                    return true;
                }
            
        }
    }

    return false;

}

bool judgePoint24(vector<int>&cards)
{
    //each card ranges bw 1,9
    //Arrange these numbers using given ops to get the value of 24
    //return true if you can get the number 24 by doing this

    vector<double>nums(cards.begin(),cards.end());
    return solve(nums);
}

int main()
{

    vector<int>cards = {4,1,8,7};

    cout<<(judgePoint24(cards) ? "Yes" : "No")<<endl;
    return 0;
}
