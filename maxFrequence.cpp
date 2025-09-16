#include<bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int>&arr)
{
    unordered_map<int, int>count;

    int maxFreq = 0;
    int maxAns = 0;


    for(int i = 0; i <arr.size(); i++)
    {
        count[arr[i]]++;
        maxFreq = max(maxFreq , count[arr[i]]);        
    }

    for(int i = 0; i<arr.size(); i++)
    {
        if(maxFreq == count[arr[i]])
        {
            maxAns = arr[i];
            break;
        }
    }

    return maxAns;


}

int main()
{
    vector<int>arr = {1,2,3,1,2};

    int ans = maxFrequency(arr);

    cout<<ans<<endl;
    
    return 0;

}
