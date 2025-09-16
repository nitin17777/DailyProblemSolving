#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

bool solve(vector<int>&teeths)
{
    //he will spin leftmost part with 1 rev per second
    //successful spin would be when rightmost part will spin with 1 rev per second

    unordered_set<int>freq;

    for(int i = 0;i<teeths.size();i++)
    {
        freq.insert(teeths[i]);
    }

    if(freq.size() < teeths.size())
    return true;

    else
    return false;
}

//     unordered_map<int,int>freq;
//     {
//         for(auto&tee:teeths)
//         {
//             freq[tee]++;
//         }
//     }
//     for(auto&p: freq)
//     {
//         if(p.second >1)
//         return true;
//     }
//     return false;

// }

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int>teeths(n);

        for(int i=0;i<n;i++)
        {
            cin>>teeths[i];
        }

        cout<<(solve(teeths) ? "Yes" : "No")<<endl;
    }
    return 0;
}
