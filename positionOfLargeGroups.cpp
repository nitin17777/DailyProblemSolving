#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<vector<int>> largeGroupPositions(string s)
{
    int n = s.length();
    //a group is considered large if it has 3 or more characters
    //we have to return the intervals of such group
    

    vector<vector<int>>ans;

    int start = 0;
    for(int i= 1 ; i<=n; i++)
    {
        if(i == n || s[i] != s[i-1])
        {
            if(i - start >= 3)
            {
                ans.push_back({start,i-1});
            }
            start = i;
        }   
        
    }
    return ans;
}


int main()
{
    string s = "aaa";

    vector<vector<int>>ans = largeGroupPositions(s);

    for(auto num: ans)
    {
        for(auto nu: num)
        {
            cout<<nu<<" ";
        }
    }

    cout<<endl;
    return 0;

}