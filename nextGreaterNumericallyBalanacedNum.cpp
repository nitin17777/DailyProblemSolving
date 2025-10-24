#include <bits/stdc++.h>
using namespace std;

/*
bool isBal(int x)
{

    string num = to_string(x);

        unordered_map<char,int>freq;
        for(auto x: num)
        {
            freq[x]++;
        }

        for(auto &x : freq)
        {
            int digit = x.first -'0';
            if(digit != x.second)return false;
        }
        return true;
}

int nextBeautifulNumber(int n)
{
    // an integer x is numerically balanced if for every digit d in number x : there are exactly d occurences of that digit in x

    //so in that number, the number should have same frequency as that numberd

    int i = n+1;

    while(true)
    {
        if(isBal(i))return i;

        i++;
    }
}
*/

vector<int> balancedNumbers;

void generate(string curr)
{

    if (!curr.empty())
    {
        long long num = stoll(curr);
        if (num > 0 && num <= 1e9)
        {
        }
    }
}

int nextBeautifulNumber(int n)
{

    if (!balancedNumbers.empty())
    {
        generate("");
        sort(balancedNumbers.begin(), balancedNumbers.end());
    }

    for (auto x : balancedNumbers)
    {
        if (x > n)
            return x;
    }
    return -1;
}

int main()
{
    cout << nextBeautifulNumber(1) << endl;
    return 0;
}