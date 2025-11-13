#include <bits/stdc++.h>
using namespace std;

int maxOperations(string s)
{
    // we will count how many zeroes are there in right of every '1' present

    int n = s.size();
    int countOne = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            while ((i + 1) < s.length() && s[i + 1] == '0')
                i++;

            ans += countOne;
        }
        else
            countOne++;
    }
    return ans;
}

/*
int maxOperations(string s)
{
    //select i such that s[i] == 1 && s[i] == 0
    //move all '1' to the end and return the number of moves required

    int n = s.size();

    //we have to make this loop run all the '1' are at the end of the string

    int count = 0;
    bool swapped = true;

    while(swapped)
    {
        for(int i = 0; i <n-1;i++)
        {
            if(s[i] == '1' && s[i+1] == '0')
            {
                swap(s[i],s[i+1]);
                count++;
                swapped = true;
            }
        }
    }
    return count;
}*/

int main()
{
    string s = "1001101";
    cout << maxOperations(s) << endl;

    return 0;
}
