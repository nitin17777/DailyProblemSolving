#include<iostream>
#include<vector
using namespace std;

int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k)

{
    //each element of this 2d subarray depicts position and amount of fruits and all are already sorted in order by position 

    //we are initially given a startPosition -> and from any position we can either walk left or right 
}

int main()
{

    vector<vector<int>>fruits = {
        {2,8}, {6,3}, {8,6}
    };

    int startPos = 5; 
    int k = 4;

    int ans = maxTotalFruits(fruits, startPos, k);

    cout<<ans<<endl;

    return 0;
    
}
