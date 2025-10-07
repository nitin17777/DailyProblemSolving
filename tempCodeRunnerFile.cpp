#include<iostream>
#include<vector>
using namespace std;

int minOps(int a, int b)
{
    //choose any +ve integer x and multiply either a or b by x

    //min tasks to make a equal to b and this is always possible

    if(a==b)return 0;

    if(a%b == 0 || b%a == 0)return 1;

    return 2;

}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int a,b;
        cin>>a>>b;

        cout<<minOps(a,b)<<endl;

    }
    

    return 0;
    
}
