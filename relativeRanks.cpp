#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> findRelativeRanks(vector<int>& score)
{

}

int main()
{

    vector<int>score = {5,4,3,2,1};
    vector<string>ans = findRelativeRanks(score);

    for(auto&an :ans)
    {
        cout<<an<<" ";
    }
    cout<<endl;
    return 0;
    
}
