#include<bits/stdc++.h>
using namespace std;

int maximumSwap(int num)
{
    //we can swap one digit at most once to get the max valued number

    string str = to_string(num);
    int n = str.size();

    for(int i = 0;i<n;i++)
    {
        for(int j = n-1;j>=0;j--)
        {
            if(str[i] < str[j])
            {
                swap(str[i],str[j]);

            }
        }
    }
    return stoi(str);

}

int main()
{
    int num = 2736;
    cout<<maximumSwap(num)<<endl;

    return 0;
    
}
