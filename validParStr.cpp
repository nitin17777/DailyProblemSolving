#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool checkValidString(string s)
{
    int n = s.size();

    //Determine if s is valid or not
    // * could be considered either as right or leftr bracket or an emepty string


    //We can try bakctracking approach to treat that * as ( or ) and that evry possible combo of * possible 

    //low = min possible number of unmatched '('
    //high = max possible number of unmatched '('
    int low=0,high=0;

    for(char c:s)
    {
        if(c=='(')
        {
            low++;
            high++;
        }

        else if(c==')')
        {
            low--;
            high--;
        }

        else
        {
            low--;
            high++;
        }
        low = max(0,low);

        if(high<0)return false;
    }
    return low == 0;
}


//Recursive approach: 
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<(checkValidString("(*))")?"True":"False")<<endl;

    return 0;
}