#include <bits/stdc++.h>
using namespace std;
/*
void func(char c,vector<bool>&visited)
{
    if(char c == 'A')
    {
        for(int i = 1;i<n;i++)
        {

        }

    }
}

vector<int>finalBlacks(string&s, vector<int>&initialB)
{
    int n = s.size();
    int m = initialB.size();

    //each cell is either black or white
    //initially m blocks are black and others are white

    //if a person is on some cell x, he might be given two types of commands:
    //A -> jump to the next cell (x+1)
    //B ->jump to the next white cell  i.e minimum y> x : y is white

    //given string consists of comamnands

    //for each i from 1 to n, starting form cell 1 , execute first i commands

    //color the last visited cell black if not

    //print all the black cells at the end and print them in increasing order


    //A -> jump to the next cell (x+1)
    //B ->jump to the next white cell  i.e minimum y> x : y is white

    //make array and firstly mark the already black ones
    vector<bool>visited(n+1, false);
    for(auto x :initialB)
    {
        visited[x] = true;
    }

    //start from i = 1: Perform the given command and color the last visited cell black as well

    for(char c: s)
    {
        int i = 1;
        if(!visited[i])
        {

        }
    }


    //Do this for i from 1 to n













}
*/
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        string s;
        cin >> n >> m >> s;

        set<int> a; // To store black cells
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            a.insert(x);
        }

        int curr = 1;
        for (char c : s)
        {
            curr++;

            // This one is for simulating correct B movement
            if (c == 'B')
            {
                while (a.count(curr))
                    curr++; // until we have that curr which is already colored black
            }
            a.insert(curr);

            // After painting, skip blacks again to prepare correct next landing position
            if (c == 'B')
            {
                while (a.count(curr))
                    curr++;
            }
        }

        cout << a.size() << '\n';
        for (auto &x : a)
            cout << x << " ";
        cout << '\n';
    }
    return 0;
}
