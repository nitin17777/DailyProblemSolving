#include<bits/stdc++.h>
#define ll long long
using namespace std;


/*bool solve(vector<int>&a,int n)

{
    ith problem has ai subtasks each subtask has 100/ai score

    if constestant solves xi subtasks of ith problem -> his score on ith problem = xi * 100/ai

    Total score of contestant = sum of their score in all the problems

    Determine if it is possble to achieve every integer total score from 0 to 100 *n
    
}
    */

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;


    //we just need to check if there exists 100 in the given array or not

    // because if we have coin =1, we can form any other coin as well
    while(t--)
    {
        int n;
        cin>>n;

        vector<int>a(n);
        bool ans = false;
        for(auto & x:a)
        {
            cin>>x;
            if(x == 100)ans=true;
        }
        cout<<(ans?"Yes":"No")<<endl;
    }

    return 0;
}