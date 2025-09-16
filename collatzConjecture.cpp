#include<iostream>
#include<vector>

using namespace std;


int solve(int k, int x)
{
    //x is even => divide by 2
    //otherwise set x to 3x +1

    //so we are given the final value after k number of iterations and now we have to find the initial given value

    if(x == 0)return 0;
   
    while(k>0)
    {
        if((x-1)%3 == 0 && (x-1)/3 > 0 &&((x-1)/3) %2 == 1)
        {
            x = (x-1)/3;
        }
        else
        {
            x = 2*x;
        }
        k--;
    }
    return x;
}

int main()
{
   int t;
   cin>>t;

   while(t--)
   {
    int k,x;
    cin>>k>>x;
    cout<<solve(k,x)<<endl;
   }
   return 0;

}
