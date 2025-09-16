#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long

using namespace std;

ll solve(vector<ll>&grump)
{
    int n = grump.size();

    //Villager i initially has a grumpiness of gi

    //Select two villagers i and j and give them max(gi, gj)emralds to share
    //And by doing this their  grumpinesses decrease by min(gi,gj)

    //Calculate min emralds  he must give away to accomplish friendship with everyone in the village

    //So the final becomes: Sort grumpiness -> make group of 2 starting from the end and just keep on adding the second number i.e the bigger number
    sort(grump.begin(),grump.end());

    ll ans =0;

    for(int i =n-1;i>=0;i-=2)
    {
        ans += grump[i]; //because we have to give max(i,j)emrald
    }
    return ans;
}

int main()
{

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<ll>grump(n);
        for(int i =0 ; i < n;i++)
        {
            cin>>grump[i];
        }
        cout<<solve(grump)<<endl;
    }
    return 0;
}
