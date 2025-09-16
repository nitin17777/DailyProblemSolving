#include<iostream>
#include<vector>

using namespace std;

int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships)
{



}

int main()
{

    vector<vector<int>>languages = {
        {1},{2},{1,2}
    };

    vector<vector<int>>friendships = {
        {1,2},{1,3},{2,3}
    };
    int n = 2;

    vector<vector<int>>ans = minimumTeachings(n,languages,friendships);

    for(auto&an:ans)
    {
        for(auto&a :an)
        {
            cout<<a<<" ";
        }
        cout<<endl;
    }
        cout<<endl;

    return 0;  
}
