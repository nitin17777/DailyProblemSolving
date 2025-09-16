#include<iostream>
#include<vector>
using namespace std;
#define ll long long
long long flowerGame(int n,int m)
{
    //x flower in first lane 
    //y flowers in the second lane

    //Alice takes the first turn 
    //In each turn player must chose one lane and pick a flower from that side
    //If no flower left , current player will win the game

    //compute number of possible pairs (x,y) that satisfies the conditions:
    //Alice must win
    //flowers in x must be in between [1,n]
    //flowers in y must be in betweenn [1,m]


    //return number of pairs that satisfies the condition

    //given two arrays select 

    //::::::::FINAL ALGO ::::::::
    //count how many x+y makes odd

    //we just have to check if one is oddand another is even ONLYYY

    ll oddN = (n+1)/2;
    ll evenN = n/2;

    ll oddM = (m+1)/2;
    ll evenM = m/2;

    //return how many pairs of even and digits are possible

    return oddN * evenM + oddM * evenN;
    
}

int main()
{
    ll ans = flowerGame(3,2);

    cout<<ans<<endl;
    return 0;
    
}
