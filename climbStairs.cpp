#include<iostream>
using namespace std;

int counts(long long n)

{
    if(n<0)
    return 0;

    if(n == 0)
    return 1;

    int ans = counts(n-1) + counts(n-2);

    return ans;


}

int main()
{

    int num = 9;

    cout<<counts(num)<<endl;
    



    return 0;

}