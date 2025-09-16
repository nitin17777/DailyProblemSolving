#include<iostream>
using namespace std;

    int countGoodArrays(int n, int m, int k) 
    {
        //A good array is an array with: each element is in range(1,m) + exactly k indices satisfy the condition(arr[i-1] == arr[i])

        //Return the number of arrays that satisfies all the above conditions

        //m : Of which all elements would be under
        //n: size of required good array




    }


int main()
{

    int n = 3,m=2,k=1;

    int ans = countGoodArrays(n,m,k);

    cout<<ans<<end;

    return 0;
}