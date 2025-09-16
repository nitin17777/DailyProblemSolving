#include<iostream>
#include<vector>
using namespace std;
#include<unordered_map>

vector<int>findEven(vector<int>&digits)
{
    //we have to form a 3digit number such that it does not have leading zeroes ,must be even and msut have all unique digits

    int n = digits.size();
    sort(digits.begin(), digits.end()); // sorting first

    unordered_map<int,int>evenNums;
    vector<int>evens;
    for(int i = 0; i < n; i++)
    {
        //find all even numbers present and these numbers will be fixed at the end of every number as the number must be unique
        // fix that found even and make combinations with the remaining number, where the number should not start with '0'

        if(digits[i] %2 == 0)
        {
            evens.push_back(digits[i]);
        }
    }

    int right = 2;
    



}



int main()
{
    vector<int>digits = {2,1,3,0};
    vector<int>ans = findEven(digits);

    for(auto an :ans)
    {
        cout<<an << " ";
    }
    cout<<endl;
    return 0;

}