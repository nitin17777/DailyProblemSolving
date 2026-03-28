#include<bits/stdc++.h>
using namespace std;


//Didn't understood this solution much fr
string findTheString(vector<vector<int>>& lcp)
{
    int n = lcp.size();

    //lcp[i][j] = length of longest common prefix bw substrings word[i,n-1] and word[j,n-1];
    

    //Return the smallest alphabetically string word that corresponds to lcp else return empty string 


    //Basic Validation

    /*Diagonal must satisfy lcp[i][i] = n-i, because suffix starting at i with itself matches fully
    */
    for(int i = 0;i<n;i++)
    {
        if(lcp[i][i] != n-i)return "";
    }


    //initiallising dsu now

    vector<int>parent(n);

    for(int i =0;i<n;i++)parent[i] = i;

    function<int(int)>find = [&](int x)
    {
        if(parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    };

    // Merging two groups now
    auto unite = [&](int a,int b)
    {
        parent[find(a)] = find(b);
    };

    //Step 1 : Merge indices
    for(int i = 0;i<n;i++)
    {
        for(int j = i;j<n;j++)
        {
            // if first characters match -> i , j must belong to the same group
            if(lcp[i][j] > 0)unite(i,j);
        }
    }


    //Step 2 : Assigning smallest characters
    unordered_map<int,char>groupChar;

    char curr = 'a';

    string word(n,'?');

    for(int i= 0;i<n;i++)
    {
        int root = find(i);

        if(groupChar.find(root) == groupChar.end())
        {
            if(curr > 'z')return "";
            groupChar[root] = curr++;
        }
        word[i] = groupChar[root];
    }

    //Validating LCP

    vector<vector<int>>dp(n,vector<int>(n,0));

    for(int i = n-1;i>=0;i--)
    {
        for(int j = n-1;j>=0;j--)
        {
            if(word[i] == word[j])
            {
                dp[i][j] = 1;

                if(i+1 < n && j+1 <n)
                {
                    dp[i][j] += dp[i+1][j+1];

                }
            }
        }
    }

    //If computed lcp != given lcp -> Invalid
    if(dp != lcp)return "";

    return word;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>lcp = {{4,0,2,0},{0,3,0,1},{2,0,2,0},{0,1,0,1}};
    cout<<findTheString(lcp)<<endl;
    return 0;
}