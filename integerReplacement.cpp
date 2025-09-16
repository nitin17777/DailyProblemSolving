#include<iostream>
#include<vector>
using namespace std;

bool isMultipleOf2(int n) {
    return (n & 1) == 0;  // true if n is even
}



int integerReplacement(int n) 
{
    //if n is even replace n by n/2
    //if n is odd replace n by n+1 or n-1 depending upon which will lead to min steps


    //return minimum number of operations to become 1

    int count = 0;
    while(n >1)
    {

        if(isMultipleOf2(n))
        {
            n/=2;
        }
        else
        {
            if(n == 3 || (n&3)==1) //since subtracting would be easier in case of 3 :n&3 means-> n%4 basically
            {
                n--;
            }
            else
            n++;
        }
        count++;
}

return count;
   
}

int main()
{

    int n = 65535;

    int ans = integerReplacement(n);

    cout<<ans<<endl;

    return 0;
    
}
