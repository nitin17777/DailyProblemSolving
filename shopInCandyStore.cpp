#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//we can get atmost  K candies for free 
//N : minimum amount of money to be spent to buy all N different candies
vector<int>candyStore(vector<int>candies,int N , int K)
{
    sort(candies.begin(),candies.end());
    int mini = 0;
    int buy = 0; // pointer for candies to buy cheapest candies first
    int free = N-1; //pointet for free candies

    while(buy <= free)
    {
        mini = mini + candies[buy];// buying the cheapest first
        buy++;
        free -= K;
    }

    int maxi =0; 
    buy = N-1; // to buy costliest candies first
    free = 0;//candies to get for free

    while(free <= buy)
    {
        maxi = maxi +candies[buy];
        buy--;
        free = free + K;
    }
    vector<int>ans;

    ans.push_back(mini);
    ans.push_back(maxi);
    return ans;

}

int main()
{

    vector<int>candies = {3,2,1,4};
    int N = 4;
    int K = 2;

    vector<int>ans = candyStore(candies,N,K);

    for(auto candy : ans)
    {
        cout<<candy<<" ";

    }
    cout<<endl;

    return 0; 

}