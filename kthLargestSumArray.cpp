#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

/*int kthLargestSumArray(vector<int>arr,int k)
{
vector<int>sumStore;
int n = arr.size();

for(int i = 0;i < n;i++)
{
    int sum = 0;

    for(int j =i; j<n; j++)
    {
        sum += arr[j];
        sumStore.push_back(sum);
    }
}

sort(sumStore.begin(), sumStore.end());

return sumStore[sumStore.size()-k];

}
*/

//Approach 2: 
int kthLargestSumArray(vector<int>arr,int k)
{
    priority_queue<int,vector<int>, greater<int>> mini;

    int n = arr.size();

    for(int i = 0; i<n; i++)
    {
        int sum = 0;
        for(int j = i; j<n;j++)
        {
            sum += arr[j];

            if(mini.size() < k)
            {
                mini.push(sum);
            }
            else
            {
                if(sum > mini.top())
                {
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }

return mini.top();
}

int main()
{
    vector<int>nums = {5,10,4,9,10};
    int k = 3;

    int anss = kthLargestSumArray(nums,k);

    cout<< anss <<endl;

    return 0;

}