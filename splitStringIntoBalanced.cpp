#include<iostream>
#include<vector>
#include<string>

using namespace std;


    int balancedStringSplit(string s)
    {
        //balanced strings are those that have an equal quantity of L and R characters

        int balance=0, count = 0;

        //take count of both and whenever both are of same quantity increase the balance count
        
        

        for(char c:s)
        {

            if(c == 'R')
            balance++;

            else
            balance--; // in case we got 'L'
            
            if(balance == 0)
            count++; //when both R and L have same quantity

        }
        return count;

    }


int main()
{

    string s = "RLRRLLRLRL";

    int ans = balancedStringSplit(s);

    cout<<ans<<endl;

    return 0;
    
}
