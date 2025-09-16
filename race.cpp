#include<iostream>
using namespace std;


bool race(int a,int x,int y) // 1,3,4    3  1  5
{
    //alice starts at position a
    //prize can appear at x or y

    //bob can start at any position except a
    //we have to check if bob can reach the prize faster than alice in both possible cases i.e. x and y

    // or simply: |bob-x| < |a -x | && |bob-y| < |a -y|

    //so we will loop over all position from 1 to 100 except a and check if there is any position which satisfies both above conditions


    for(int bob = 1; bob<=100; bob++)
    {
        if(bob == a)continue; // since bob can't start from alice's position

        int bobDisx = abs(bob - x);
        int aliceDisx = abs(a-x);

        int bobDisy = abs(bob - y);
        int aliceDisy = abs(a-y);


        if((bobDisx < aliceDisx) && (bobDisy < aliceDisy))
        {
            return true;

        }
    }
    //if at the end of loop no such condition found
    return false;
} 

int main()
{    
    int t;
    cin>>t; // number of testCases

    while(t--)
    {
        int a,x,y;
        cin>>a>>x>>y;

        if(race(a,x,y))
        {
            cout<<"YES"<<endl;

        }

        else
        {
            cout<<"NO"<<endl;
        }
    }

    return 0;

}