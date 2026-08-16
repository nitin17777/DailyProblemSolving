#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> addToArrayForm(vector<int>& num, int k)
{
    int i = num.size() - 1;

        while (i >= 0 || k > 0) {
            if (i >= 0) {
                k += num[i];
                num[i] = k % 10;
                k /= 10;
                i--;
            } else {
                num.insert(num.begin(), k % 10);
                k /= 10;
            }
        }

        return num;

}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>num = {1,2,3};

    vector<int>ans = addToArrayForm(num);

    for(auto& x:ans)cout<<x<<" ";

    cout<<endl;

    

    return 0;
}