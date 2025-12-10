#include<bits/stdc++.h>
using namespace std; 

int  fact(int n)
{
    if(n == 0)return 1;

    return n * fact(n-1);
}

int countPermutations(vector<int>& cs)
{
    int n = cs.size();
    /*
    Password for ith computer is cs[i]

    Password for computer labeled 0 is alredy decrypted and serves as root, annd all computers must be unlocked using it or another already unlocked computers


    We can decrypt password of computer i using passowrd for comp j : j<i && cs[j] < cs[i]

    Find number of perms of 1 - n-1, 

    */

    int num = cs[0];
    for(int i = 1 ; i < n;i++)
    {
        if(cs[i] == num)return 0;
    }

    return fact(n-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>coms = {1,2,3};
    cout<<countPermutations(coms)<<endl;


    return 0;
    
}