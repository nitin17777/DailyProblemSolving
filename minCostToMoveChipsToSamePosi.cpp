#include<iostream>
#include<vector>

using namespace std;

int minCostToMoveChips(vector<int>& position) 
{
    //position of ith chip is position[i]

    //we need to move all chips to the same position

    //in one step, we can change the position of ith chip from position[i] +2 or position[i] -2 for cost=0 and position[i] +1 or position[i] -1 for cost =1
    
    //return the min cost needed to move all chips to the same position

    //we only have to pay money when we parity changes like odd even and vice versa

    int even =0, odd=0; //*******//
    for(int pos : position)
    {
        if(pos%2 == 0)even++;
        else odd++;
    }
    return min(even,odd);



}

int main()
{

    vector<int>position = {1,2,3};

    int ans =minCostToMoveChips(position);

    cout<<ans<<endl;

    return 0;
    
}
