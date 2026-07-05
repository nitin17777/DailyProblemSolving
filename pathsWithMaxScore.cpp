#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> pathsWithMaxScore(vector<string>& board)
{

}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string>b = {"E23","2X2","12S"};
    vector<int>ans = pathsWithMaxScore(b);
    for(auto&x:ans)cout<<x<<" ";

    cout<<'\n';


    return 0;
}