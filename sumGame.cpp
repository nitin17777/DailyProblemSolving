#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool sumGame(string num)
{

    

    //Alice starts first

    //In each ove theey will replace any num[i] with any digit
    //The game ends when no more ?  is left
    
    // Bob wins when : Sum of digits in 1st half should be equal to sum of digits in second half

    //True if alice wins 
    //alice will always try to fill 

    int n = num.size();

    //sum = current difference bw rwo halves :left contributes positively and right half contributes negatively
    int sum = 0;

    //q=difference in number of '?' in left and right half

    int q = 0;

    for(int i = 0;i<n;i++)
    {
        if(num[i]=='?')
        {
            if(i<n/2)q++;
            else q--;
        }

        else
        {
            int digit = num[i]-'0';
            if(i<n/2)sum+=digit;
            else sum-=digit; 
        }      
    }

    // if q is odd Alice will always win
    if(q%2 != 0)return true;

    //Bob can only win when sum == -9 * q/2
    return sum != -9 *q/2;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<(sumGame("5023")?"true":"false")<<'\n';

    return 0;
}