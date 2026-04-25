#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool self(int num)
{

    int n = num;

    while(n)
    {
        int a = n%10;

        if(a==0 || num%a != 0)return false;

        n/=10;
    }

    return true;
}

vector<int> selfDividingNumbers(int left, int right)
{
    //self dividing = number which is divisible by every digit inside it

    vector<int>ans;

    for(int i = left;i<=right;i++)
    {
        if(self(i))ans.push_back(i);
    }
    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>ans = selfDividingNumbers(1,22);
    for(auto& x:ans)cout<<x<<" ";

    cout<<endl;

    return 0;
}
