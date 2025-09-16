#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

bool isValidHalf(int team1,int team2)
{
    if(max(team1,team2) <=2)
    return true;


    int maxGoals = max(team1,team2);
    int minGoals = min(team1,team2);

    int requiredSeparators = (maxGoals - 1) / 2;

    return minGoals >= requiredSeparators;//true if separators are sufficient to be filled after 3 consecuitve goals

}

bool solve(int a,int b,int c,int d)
{

    //No team would score 3 consecutive goals in the same half

    //Score at the end of first half was a:b(r:k)

    //Score at the end of 2nd half : c:d(r:k)

    //we have to determine whether his dream can come true

    if(c<a || d<b)return false;

    if(!isValidHalf(a,b))return false;

    int secondHalfR = c-a;
    int secondHalfK = d-b;

    if(!(isValidHalf(secondHalfR,secondHalfK)))
    return false;

    return true;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<(solve(a,b,c,d) ? "Yes" : "No")<<endl;
    }
    return 0;
}
