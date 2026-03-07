#include<bits/stdc++.h>
using namespace std;

int minFlips(string s)
{
    int n = s.size();

    // Op 1 : Remove char at the start of s and append it to the end of the string
     
    //Op 2 : Pick any char and simply flip it's value

    //Return min ops to make the string alternating

    string s2 = s+s;

    int ans = INT_MAX;

    int mis1 = 0,mis2=0;// mismatches with pattern 010101... and 101010..respectively

    int left = 0;

    for(int right = 0; right<2*n; right++)
    {
        char ex1 = (right%2 ==0)?'0':'1';
        char ex2 = (right%2 ==0)?'1':'0';

        //Counting mismathces now
        if(s2[right] != ex1)mis1++;
        if(s2[right] != ex2)mis2++;

        //Maintaining window size of n
        if(right-left+ 1>n)
        {
            //Expected chars for left window
            char leftex1 = (left%2 ==0)?'0':'1';
            char leftex2 = (left%2 ==0)?'1':'0';

            //Remove contribution of left element
            if(s2[left] != leftex1)mis1--;
            if(s2[left] != leftex2)mis2--;

            left++;
        }

        //check ans once the window size becomes n
        if(right -left+1 == n)
        {
            ans = min(ans,min(mis1,mis2));
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<minFlips("111000")<<endl;

    
    return 0;
}