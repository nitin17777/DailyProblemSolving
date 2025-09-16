#include<iostream>
#include<vector>

using namespace std;


bool doesAliceWin(string s) 
{
    
    string vowels = "aeiou";

    //alice starts first

    //on alice's turn she has to remove any non empty substring that contains an od odd numbr of vowels

    //on bob's turn he has to remove any non empty substring that contains  even number of vowels

    //first player to not able to make a move will lose the game

    //return true if alice wins the game


    //alice's turn first

    for(auto&ch : s)
    {
        if(vowels.find(ch) != string::npos)
        return true;
    }
    return false;
}


int main()
{
    cout<<(doesAliceWin("leetcoder")? "true" : "false")<<endl;
    return 0;   
}

