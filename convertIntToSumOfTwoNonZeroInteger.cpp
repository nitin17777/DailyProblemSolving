#include<iostream>
#include<vector>
using namespace std;


bool isNonZero(int x)
{
    while(x>0)
    {
        if(x%10 == 0)return false;
        x/=10;

    }
    return true;
    
}

vector<int> getNoZeroIntegers(int n) 
{
    //we have to return list of  two integers a and b such that a+b = n
    vector<int>ans;

    for(int a = 1;a<n;a++)
    {
        int b = n-a;

        if(isNonZero(a) && isNonZero(b))
        {
            ans.push_back(a);
            ans.push_back(b);
            break;
        }
    }

    return ans;    
}

int main()
{    
    vector<int>ans = getNoZeroIntegers(11);
    for(auto&an :ans)
    {
        cout<<an<<" ";
    }
    cout<<endl;

    return 0;

}