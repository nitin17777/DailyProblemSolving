#include<bits/stdc++.h>
using namespace std;

vector<int> time(string s,vector<int>queries)
{
    int n = queries.size();
    
    
    // A => Decrease x by 1
    // B => Replace x with the GIF of half of it's value

    //we put each num of query starting from given machine, and move it to B and this process continues till that number becomes 0. Each move takes 1 second, we need to find total seconds required to solve all the queries

    int totalTime = 0;
    vector<int>ans;


    for(int i = 0;i < n;i++)
    {

        int x = queries[i];

        while(x>0)
        {
            for(auto ch : s)
            {

                if(x == 0)break;
                

                if(ch == 'A')
                x-=1;

                else if(ch == 'B')
                {
                    x/=2;
                }
                totalTime++;
            }
        }
        ans.push_back(totalTime);
        totalTime = 0;
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,q;
        cin>>n>>q;

        string s;
        cin>>s;

        vector<int>queries(q);
        for(int i = 0;i < q ; i++)
        {
            cin>>queries[i];
        }
        vector<int>ans = time(s,queries);

        for(auto an: ans)
        {
            cout<<an<<endl;
        }
    }
    return 0;
}