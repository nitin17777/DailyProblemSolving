#include<bits/stdc++.h>
#define ll long long
using namespace std;

int openLock(vector<string>& deadends, string target)
{
    int n = deadends.size();

    /*

    initially -> '0000' -> Represents state of 4 wheels 

    If encounterd any deadend -> lock will stop turning and we will be unable to opne it

    Return min number of turns to open lock else return -1

    */

    string curr = "0000";

    unordered_set<string>dead;
    for(auto&x:deadends)dead.insert(x);

    if(dead.count("0000"))return -1;


    queue<string>q;
    q.push("0000");

    //Storing visited states
    unordered_set<string>vis;
    vis.insert("0000");

    int turns = 0;


    while(!q.empty())
    {
        int sz = q.size();

        //Processing all states at current BFS level
        while(sz--)
        {
            string curr = q.front();
            q.pop();

            if(curr==target)return turns;

            //try changing each of 4 wheels

            for(int i = 0;i<4;i++)
            {
                //Moving wheel up
                string next = curr;
                if(next[i] == '9')next[i]='0';

                else next[i]++;

                if(!dead.count(next) && !vis.count(next))
                {
                    vis.insert(next);
                    q.push(next);
                }

                //If wheel is moved down
                next=curr;

                if(next[i] == '0')next[i] = '9';
                else next[i]--;


                if(!dead.count(next) && !vis.count(next))
                {
                    vis.insert(next);
                    q.push(next);
                }
            }
        }
        turns++;
    }
    return -1;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string>deadends = {"0201","0101","0102","1212","2002"};
    cout<<openLock(deadends,"0202")<<endl;

    return 0;
}