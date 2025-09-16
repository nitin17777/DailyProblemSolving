#include<iostream>
#include<vector>

using namespace std;

void tower(int n,char fromRod,char auxRod,char toRod)
{
    if(n == 1)
    {
        cout<<"Move disk 1"<<fromRod<<"to"<<toRod<<endl;
    }

    tower(n-1,fromRod,auxRod,toRod);
    cout<<"Move disk"<<n<<"from"<<fromRod<<"to"<<toRod<<endl;

    tower(n-1,auxRod,toRod,fromRod);
}

int main()
{


    return 0;
    
}
