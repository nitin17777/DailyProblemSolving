#include<bits/stdc++.h>
#define ll long long
using namespace std;


// //So find all possible perms and check the given condition
// void backtrack(vector<int>&a,vector<int>&path,vector<vector<int>>&ans,vector<bool>&used)
// {
//     if(path.size() == a.size())
//     {
//         ans.push_back(path);
//         return;
//     }

//     for(int i = 0;i<a.size();i++)
//     {
//         if(used[i])continue;

//         path.push_back(a[i]);
//         used[i] = true;

//         backtrack(a,path,ans,used);

//         path.pop_back();
//         used[i] = false;
//     }
// }

// vector<vector<int>>perms(vector<int>&a)
// {
//     int n = a.size();

//     vector<vector<int>>ans;
//     vector<bool>used(n,false);
//     vector<int>path;
//     backtrack(a,path,ans,used);
//     return ans;
// }


// bool check(vector<int>&a)
// {
//     int n = a.size();

//     for(int i = 0;i<n;i++)
//     {
//         if(a[i]%(i+1) != 0 || (i+1)%a[i] != 0)return false;
//     }
//     return true;
// }

// int countArrangement(int n)
// {
//     //beautiful if : for every i : perm[i] is divisible by i and i is divisble by perm[i], return the number of beautiful arrangements that we can construct 

//     vector<int>a;
//     for(int i = 1;i<=n;i++)a.push_back(i);

//     vector<vector<int>>allPerms = perms(a);

//     int cnt = 0;
//     for(auto &arr:allPerms)
//     {
//         if(check(arr))cnt++;        
//     }
//     return cnt;
// }

//optimised approach now


int cnt = 0;
void backtrack(int pos,int n, vector<bool>&used)
{
    if(pos>n)
    {
        cnt++;
        return;
    }

    for(int num = 1;num<=n;num++)
    {
        if(used[num])continue;

        if(num%pos == 0 || pos%num == 0)
        {
            used[num] = true;
            backtrack(pos+1,n,used);

            used[num] = false;
        }
    }
}

int countArrangement(int n)
{
    vector<bool>used(n+1,false);

    backtrack(1,n,used);

    return cnt;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<countArrangement(2)<<endl;
    
    return 0;
}