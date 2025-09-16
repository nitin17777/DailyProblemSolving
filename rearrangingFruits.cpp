#include<iostream>
#include<vector>
using namespace std;

long long minCost(vector<int>& basket1, vector<int>& basket2)
{
    //we are given 2 equal baskets and we have to make them same. And in order to make them same we can use this operation: choose index i and j and swap ith index of basket1 with jt index of basket2
    
    //and cost of swap is min(basket1[i],basket2[j]

    //two baskets are considered equal if sorting them make them exactly the same

    //so basically we have to do something like which makes the sum of both array equal and find the cost

    
}

int main()
{

    vector<int>basket1 = {4,2,2,2};
    vector<int>basket2 = {1,4,1,2};

    long long ans = minCost(basket1 , basket2);

    cout<<ans<<endl;

    return 0;
    
}
