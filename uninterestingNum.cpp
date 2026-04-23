#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool solve(string num)
{

    /*

    Choose one of it's digit -> square it and replace original digit with this square value

    Can we obtain a number that is divible by 9 by performing this operation any number times


    Divisble by 9 when : sum of it's digit is divible by 9
    
   
    Find sum -> count number of 2s and 3s

    */


    ll original = 0;
    int two = 0, three= 0;

    for(char c : num)
    {
        int d = c-'0';
        original += d;

        if(d==2)two++;
        else if(d==3)three++;
        
    }


    if(original % 9 == 0)return true;

    //now if we changed x 2s and y 3s -> then sum increases by 2x + 6y

    for(int x = 0; x<=min(two,9);x++)
    {
        for(int y = 0;y<= min(three,9);y++)
        {
            if((original + x*2 + y*6) % 9 == 0)return true;
        }
    }
    return false;  
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        string n;
        cin>>n;

        cout<<(solve(n)?"YES":"NO")<<endl;
    }

    return 0;
}