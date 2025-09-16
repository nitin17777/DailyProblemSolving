#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int totalFruits(vector<int>& fruits) 
{
    //we have to collect max fruits considering some restrictions in mind:
    //we have only 2 baskts and one basket can only contain single type of fruit and we can store unlimited fruits in the basket

    // starting from any tree we must exactly pick one fruit from every tree nc start tree while moving to right and once we reach a tree that cannot fit int your basket we must stop...We have to return the max fruits we can pick

    //so we can go with a sliding window until 2 same numbers are coming and as soon as any other number comes in jsut slide the window to right

    int n = fruits.size();
    int left = 0;
    unordered_map<int,int>freq;
    int count = 0;
    int maxx = 0;

    for(int right = 0; right<n; right++)
    {
        freq[fruits[right]]++;

        //if more than 2 types of fruits are there, shrink the window from left
        while(freq.size() > 2)
        {
            freq[fruits[left]]--;
            //and now if frequency of this fruit is zero, jus tismply remove the fruit from the frequecny count map
            if(freq[fruits[left]] == 0)
            {
                freq.erase(fruits[left]);
            }
            left++;
        }
        maxx = max(maxx ,right - left+1);
    }
    return maxx;


}


int main()
{
    vector<int>fruits = {0,1,2,2};

    int ans = totalFruits(fruits);

    cout<<ans<<endl;

    return 0;

}