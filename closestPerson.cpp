#include<iostream>
using namespace std;

int findClosest(int x, int y, int z) 
{
    //Person 1 and person 2 move towards person 3 at same speed

    if(abs(z-x) < abs(z-y))
    {
        return 1;

    }
    else if(abs(z-y) < abs(z-x))
    {
        return 2;
    }
    else return 0;

}


int main()
{
    cout<<findClosest(2,7,4);
    
    return 0;

}