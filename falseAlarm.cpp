#include<iostream>
#include<vector>
using namespace std;


bool canPass(int n,int buttonSec,vector<int>&doors)
{

    //he need to pass all the doors from 1 to n in order of number and reach the exit

    //each door can be open or close, if a door is open he can pass through it in 1 second and if it is closed he can't pass through it at all

    // he can use a button which makes all closed doors open for x seconds

    //we have to check if he can pass through all the doors or not


    //0 -> Open
    //1 -> Closed


    for(int i = 0; i < n; i++)
    {
        bool possible = true;

        for(int j = i;j <n; j++)
        {
        if(doors[j] == 1)
        {
            buttonSec--;
        }
        else
        {
            buttonSec--;
        }

        if(buttonSec < 0)
        {
            possible =false;
            break;
        }

        }
        if (possible)
        return true;
        
    }
    return false;
    

}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n , x;
        cin>>n>>x;

        vector<int>doors(n);

        for(int i = 0; i<n;i++)
        {
            cin>>doors[i];
        }

        if(canPass(n,x,doors))
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