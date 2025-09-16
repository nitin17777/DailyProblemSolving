#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int numEquivDominoPairs(vector<vector<int>>& dominoes)
{
    //two dominoes are equivalent if a == c  && b == d  || a==d && b==c ->one domino can be rotated to be equal to another domino

    unordered_map<int,int>count;

    int result = 0;

    for(const auto&d : dominoes)
    {
        int a = min(d[0], d[1]);
        int b = max(d[0], d[1]);

        //Now unique key generation in order to save that a pair with same values already exist

        int key = a*10 + b;

        result += count[key];
        count[key]++;
    }
    return result;   
}


int main()
{

    vector<vector<int>>dominoes = {{1,2}, {2,1}, {3,4}, {5,6}};

    int ans = numEquivDominoPairs(dominoes);

    cout<<ans<<endl;

    return 0;

}