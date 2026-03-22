#include<bits/stdc++.h>
using namespace std;

bool solve(string&s,string&r)
{
    int n = s.size();

    /*We can perform n-1 ops on s : 
    Choose index k : sk != sk+1, if it is impossible to choose such index, we loose
    Then replace sk sk+1 with ri, and this will result in decrement in size of our array by 1




    Determine if we can win the game

    */

    //We just need to maintain 0 and 1 in the array till the end, else return No

    int cnt1 = count(s.begin(),s.end(),'1'),cnt0 = n - cnt1;

    for(int i =0;i<n-1;i++)
    {
        //In case we will fail to make any move till the end of the game
        if(cnt0 == 0 || cnt1 == 0)
        {
            return false;
        }

        //will lead to decrement of '0' in the string then
        if(r[i] == '1')cnt0--;
        else cnt1--;//Otherwise  '1' count will decrease   
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        string s,r;
        cin>>s>>r;

        cout<<(solve(s,r)?"Yes":"No")<<endl;
        
    }
    return 0;
}