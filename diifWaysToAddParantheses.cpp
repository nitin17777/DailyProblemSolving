#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> diffWaysToCompute(string expression)
{

    //we are given a string expression, and we have to return all the possible result which came by all ways of grouping numbers and operators

    vector<int>ans;

    
}




int main()
{

    string expression = "2-1-1";

    vector<int>ans = diffWaysToCompute(expression);

    for(auto& num : ans)
    {
        cout<<num<<endl;
    }
    return 0;
    
}
