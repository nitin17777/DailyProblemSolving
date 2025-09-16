#include<iostream>
using namespace std;

bool canIWin(int maxChoosableInteger, int desiredTotal)
{
    //we have to check whether the player can win the game if started first

    if(maxChoosableInteger >= desiredTotal)
    return true;

    //start counting from 1st player with first step as maxCho...Int and then check if 1st player can make the final winning move

    int first = 0, second = 0;
   
}

int main()
{

    int maxChoosableInteger = 10;
    int desiredTotal = 11;

    if(canIWin)
    cout<<"True"<<endl;

    else
    cout<<"False"<<endl;



    return 0;

}