#include<iostream>
#include<climits>
#include<string>
#include<algorithm>
using namespace std;

int maximumSwap(int num) 
{
    //we can do max of 2 swaps to turn the given number into max possible valued number

    //we have to basically swap the 0th index with the max digit which is presnet over there, and if 0th digit is already largest , move to the 1st index and so on


    string nums = to_string(num);
    
    
     
}



int main()
{
    int num = 2736;
    int ans = maximumSwap(num);

    cout<<ans<<endl;

    return 0;

}