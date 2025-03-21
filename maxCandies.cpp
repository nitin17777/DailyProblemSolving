#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


 //each element in array denotes pile of candies of size candies[i]

//we have to allocate piles of candies to k children such that each child gets same number of candies 

//each child can get candies from only pile and some piles can go unused
    //we have to return max number of candies each child can get



    bool canDistribute(vector<int>&candies , long long k , int mid)
    {
        long long count = 0;
        for(int c : candies)
        {
            count += c/mid;
        }
        return count >=k;
    }
        


int maximumCandies(vector<int>& candies, long long k) 
{

    //base case  : when candies < no. of childrens
    int n = candies.size();
    int sumOfCandies = 0;
    int minPile = 0;


    for(int i =0; i<n; i++)
    {
        sumOfCandies += candies[i] ; // found sum of all candies present   
    }

    if(sumOfCandies < k)
    {
        return 0;
    }
     // now we have to find the minimum number of candies in the array and make every element equal to that.
     // if number of all made elements >= no. of candies 'k' return 







}


int main()
{



    return 0;

}