#include<bits/stdc++.h>
using namespace std;

vector<string> letterCombinations(string digits)
{

    if(digits.empty())return{};

    //Return all possible combo of letters that the number could represent

    unordered_map<char,string>phoneMap = {
        {'2',"abc"}, {'3',"def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"},
        {'9',"wxyz"}
    };

    vector<string>result;
    string current;


    function<void(int)>backtrack = [&](int index)
    {
        //Base case : When we have processed all digits associated with current entered number
        if(index == digits.size())
        {
            result.push_back(current);
            return;
        }


    string letters = phoneMap[digits[index]];

    for(char c:letters)
    {
        current.push_back(c);
        backtrack(index+1);
        current.pop_back();
    }
    };

    //Starting our backtracking from first digit
    backtrack(0);

    return result;

}

int main()
{
    vector<string>ans = letterCombinations("23");

    for(auto&an : ans)
    {
        cout<<an<<" ";

    }
    return 0;

}