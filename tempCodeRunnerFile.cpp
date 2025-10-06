#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int minSwapsCouples(vector<int>& row)
{

    //n couples sitting in 2n seats
    //row[i] is the index of person sitting in the ith seat

    //couples are numbered in order first couple being (0,1),second : (2,3) .....(2n-2,2n-1)

    //return the min swaps required such that every couple is sitting side by side

    //couple number = personID/2
    
    //Swap: simple swapping of both persons


    int n = row.size();
    unordered_map<int,int>pos;

    for(int i = 0;i< n;i++)
    pos[row[i]] = i;

    int swaps = 0;

    for(int i = 0;i<n;i+=2)
    {
        int first = row[i];
        int partner = first ^ 1;//finding partner :since  couples differ by one bit only 

        if(row[i+1] != partner)
        {
            swaps++;
        
        int partnerPos = pos[partner];

        //swap person in position i+1 with person at position partnerPos
        swap(row[i+1], row[partnerPos]);

        //updating their positions
        pos[row[partnerPos]] = partnerPos;
        pos[row[i+1]] = i+1;

        }
    }
    return swaps;
}


int main()
{
    vector<int>row = {0,2,1,3};
    cout<<minSwapsCouples(row)<<endl;

    return 0;

}