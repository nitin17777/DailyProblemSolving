#include<bits/stdc++.h>
using namespace std;

struct pump
{
    int petrol;
    int distance;

};

class Solution
{
    public:


    int tour(pump p [], int n)
    {
        int deficit = 0;
        int balance = 0;
        int start =0;

        for(int i =0; i<n; i++ )
        {
            balance += p[i].petrol - p[i].distance;

            if(balance < 0)
            {
                deficit += balance;
                start = i+1;
                balance = 0;
            }

        }
        if(deficit + balance >= 0)
        {
            return start;
        }

        else
        {
            return -1;

        }

    }
};



int main()
{

    pump p[] = {{4,6},{6,5},{7,3},{4,5},};

    int n = sizeof(p)/ sizeof(p[0]);

    


    Solution obj;

    int start = obj.tour(p,n);

    if(start == -1)
    {
        cout<<"No possible tour"<<endl;

    }
    else
    {
        cout<<"Start is : "<<start<<endl;

    }



    return 0;
    
}