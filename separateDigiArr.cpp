#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int>separateDigits(vector<int>& nums)
{
    vector<int>ans;

    for(auto &x: nums)
    {
        vector<int>temp;
    
        int num = x;
        if(num == 0)temp.push_back(0);
        while(num > 0)
        {
            temp.push_back(num%10);
            num/=10;
        }
        reverse(temp.begin(),temp.end());
        for(auto & x:temp)ans.push_back(x);
    }
    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>a = {13,25,83,77};

    vector<int>ans = separateDigits(a);
    for(auto &x:ans)cout<<x<<" ";

    cout<<endl;


    return 0;
}