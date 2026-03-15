#include<bits/stdc++.h>
using namespace std;


//Method 1: Divide & Conquer  + Recursion
vector<int> diffWaysToCompute1(string exp)
{

    //return all possible results from computing all different possible ways to group numbers and operators

    vector<int>res;

    for(int i = 0;i<exp.size();i++)
    {
        char c = exp[i];

        //IF any operator is found
        if(c=='+' || c == '-' || c== '*')
        {
            string leftP = exp.substr(0,i),rightP = exp.substr(i+1);
            
            vector<int>leftRes = diffWaysToCompute1(leftP),rightRes = diffWaysToCompute1(rightP);

            //Combining results now
            for(int l : leftRes)
            {
                for(int r : rightRes)
                {
                    if(c=='+')res.push_back(l+r);
                    else if( c=='-')res.push_back(l-r);
                    else res.push_back(l*r);
                }
            }
        }
    }

    if(res.empty())
    {
        res.push_back(stoi(exp));
    }
    return res;
}

//Now using memoization approach now
unordered_map<string,vector<int>>memo;

vector<int> diffWaysToCompute2(string exp)
{

    //If this already solved -> return the precomuputed result and this avoid recomputing the same sub exp
    if(memo.count(exp))
    {
        return memo[exp];
    }
    

    vector<int>res;

    for(int i =0 ; i < exp.size();i++)
    {
        char c = exp[i];

        if(c=='+' || c=='-' || c=='*')
        {
            string leftP = exp.substr(0,i),rightP = exp.substr(i+1);

            //Recursively solving both parts 
            vector<int>leftRes = diffWaysToCompute2(leftP), rightRes = diffWaysToCompute2(rightP);

            for(int l : leftRes)
            {
                for(int r :rightRes)
                {
                    if(c == '+')res.push_back(l+r);
                    if(c == '-')res.push_back(l-r);
                    if(c == '*')res.push_back(l*r);
                }
            }
        }
    }

    if (res.empty())
    {
        res.push_back(stoi(exp));
    }

    memo[exp] = res;

    return res;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>ans = diffWaysToCompute2("2-1-1");

    for(auto & an:ans)cout<<an<<" ";

    cout<<endl;
    return 0;
}