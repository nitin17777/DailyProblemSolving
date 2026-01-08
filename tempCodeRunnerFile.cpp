#include<bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& bills)
{
    /*
    Each costs 5

    Each customer will buy one at a time and pay with 5,10 or 20 

    We have to return the correct change such that bill amount is 5 


    Return true if we can give the changes back properly to every customer
    */
   int five = 0,ten= 0;

    for(int b:bills)
    {
        if(b==5)five++;
        
        
        else if(b == 10)
        {
            if(five == 0)return false;

            five--;
            ten++;
        }

        else//When bill is of 20 
        {
            if(ten > 0 && five >0)
            {
                ten--;
                five--;
            }

            else if(five >=3)
            {
                five-=3;
            }
            else return false;
        }
    }
    return true;
    
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>bills = {5,5,5,10,20};
    cout<<(lemonadeChange(bills)?"True": "False")<<endl;
    return 0;
}