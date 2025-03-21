#include<iostream>
using namespace std;

int min_operations(string blocks,int k)
{
    int n = blocks.size();

    //counting total 'W's first


    int white_count =0 ,min_ops;


    for(int i =0;i<k;i++)
    {
        if(blocks[i] == 'W')
    
        white_count++;
        
    }

    min_ops = white_count;


    //main sliding window concept
    for(int i = k; i<n; i++)
    {
        if(blocks[i-k] == 'W')
        {
            white_count--;

        }
        if(blocks[i] == 'W')
        white_count++;

        min_ops = min(white_count, min_ops);

    }
    return min_ops;



}

int main()
{

    string str = "WWWBBBWBWBW";
    int ki = 6;
     
    int ans = min_operations(str,ki);

    cout<<ans<<endl;

    return 0;

}