#include<bits/stdc++.h>
using namespace std;

int solve(int a1,int a2,int a3,int a4)
{
    /*

    a-> A+B
    b-> A
    c-> B
    d-> None

    Initial mood = 0;

    If heard a joke they like,their moods increase by 1
    And if not liked, their mood decreases by 1

    If mood becomes negative, they leave the show 

    Ends the show when: When someone leaves and eve gets sad
                        If no one leaves and eve is out of jokes 

    So Eve wants to arrnage her jokes such that show lasts as longer as possible 

    Determine the max jokes she can make before the show ends

    */


    //Let Eve tell joke of 1st type initially and joke of 4th type at last

    //We will tell the jokes of type2 and type 3 in pairs until one runs out


    /*
    Total jokes = a1 -> Type 1
                2 * min(a2,a3) -> paired 2 and 3 type jokes
                min(a1 + 1,abs(a2-a3) + a4) ->Final harmful for both jokes
    */

    if(a1 == 0)return 1;

    else return (a1+ min(a2,a3)*2 + min(a1+1, abs(a2-a3) + a4));

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<solve(a,b,c,d)<<endl;
    }
    return 0;
}