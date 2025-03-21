#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;
int main()
{
vector<int>v;

v.push_back(1);
v.push_back(3);
v.push_back(6);
v.push_back(7);


cout<<binary_search(v.begin(),v.end(),3)<<endl;

cout<<"Lower Bound: "lower_bound(v.begin(),v.end(),3)-v.begin()<<endl;



}