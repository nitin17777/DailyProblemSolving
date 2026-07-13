#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> sequentialDigits(int low, int high)
{
    //Sequential digit = if each digit is one more than the previous digit

    vector<int>ans;

    //Generating all possible numbers and pushing the number which satisfies
    for(int start = 1; start<=9; start++)
    {
        int num = 0;

        for(int digit = start; digit<=9; digit++)
        {
            num = num*10 + digit;

            if(num>=low && num <= high)ans.push_back(num);
        }
    }

    sort(ans.begin(),ans.end());
    return ans;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>ans = sequentialDigits(100,300);

    for(auto & x:ans)cout<<x<<" "; 
    cout<<endl;

    return 0;
}