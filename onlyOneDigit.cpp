#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int oneDigit(int x)
{

    //we are given a number x now we need to find the smallest number such that both x and y share a common number betweeen them

    //x= 96 : y = 6


    //we want to hover over every digit and look for the smallest digit presnet

    int minDigit = INT_MAX;

    vector<int>digits;
    while(x>0)
    {
        digits.push_back(x%10);
        x/=10;
    }


    for(int i = 0; i < digits.size();i++)

    {
        if(digits[i] < minDigit)
        {
            minDigit = digits[i];
        }

    }
    return minDigit;


}

int main()
{
    int t;

    cin >> t;

    while(t--)
    {
        int x;
        cin>>x;

        cout<< oneDigit(x)<<endl;
    }



    return 0;
    
}
