#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// brute force method will be that , it will have all zeroes in the row
//And it's row will have all '1' except diagonal element


bool knows(vector<vector<int>> & M , int a , int b,int n)
{
    if(M[a][b] == 1)
    {
        return true;
    }
    else
    {
        return false;   
    }
}

int celeb(vector<vector<int>> & M, int n)
{
    stack<int>s;

    //step 1-> Push all elements in stack
    for(int i=0; i<n; i++)
    {
        s.push(i);
    }


    //step2->
    while(s.size() > 1)
    {
        int a = s.top();
        s.pop();

        int b= s.top();
        s.pop();

        if(knows(M,a,b,n))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }

    //Now the single left candidate is potential candiadate so we need to verify it

    int candidate = s.top();
    int zeroCount = 0;

    for(int i = 0;i<n;i++)
    {
        if(M[candidate][i] == 0)
        {
            zeroCount++;
        }

        if(zeroCount != n)
        {
            return -1;

        }
        int oneCount = 0;


        for(int i = 0; i<n; i++)
        {
            if(M[i][candidate]== 1)
            oneCount++;
        }

        if(oneCount != n-1)
        {
            return -1;

        }
        return candidate;
    }
}

int main()
{

    vector<vector<int>>arr = {
        {0,1,0},
        {0,0,0},
        {0,1,0}

    };

    int ans = celeb(arr,3);

    cout<<ans<<endl;
    


    return 0;

}