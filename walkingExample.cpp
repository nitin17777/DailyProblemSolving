#include<iostream>
using namespace std;

void reachHome(int src,int dest)
{

    cout<<"Source "<<src<<" destination "<<dest<<endl;

    //base case

    if(src == dest)
    {
        cout<<"Reached."<<endl;
        return;

    }
    src++;
    //recursive call

    reachHome(src,dest);

}

int main()
{ 
    int dest =  10;
    int src = 1;


cout<<endl;

    reachHome(src,dest);




    
    return 0;

}