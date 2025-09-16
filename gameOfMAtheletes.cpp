#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int solve(int n , int k , vector<int>&board)
{
    //there are n integers on board and n is even 

    //game lasts for n/2 turns , and these events happens sequentially : Alice selects an integer formo board and erases it: a

    //bob does the same :b 

    //a+b = k, and this will add 1 to the/ score

    //alice ->minimise && bob -> maximise->so alice will always try to break the pair

    //find the score at the end of the game ->and bob will always try to make the pair

    //we have to find all those pairs alice wont be able to break


    //since alice moves first, she can destory max n/2 pairs of them
    unordered_map<int,int>freq;
    
    //counting frequency of each element
    for(auto&an :board)
    {
        freq[an]++;
    }
    int possiblePairs = 0;

    //find all pairs (x,k-x)
    for(auto&it : freq)
    {
        int x = it.first;
        int y = k-x;


        if(freq.find(y) != freq.end()) //if y is present there
        {
            if(x == y)
            {
                possiblePairs+=freq[x]/2;
                
            }

            else if(x<y)
            {
                
            int pairs = min(freq[x] , freq[y]);
            possiblePairs += pairs;
            }
        
        }
    }

    int aliceTurns = n/2;

    int finalScore = max(0,possiblePairs - aliceTurns);

    return finalScore;

}

int main()
{

    int t;
    cin>>t;
    
    while(t--)
    {
        int n ,k;
        cin>>n>>k;
        
        vector<int>board(n);
        for(int i = 0 ; i < n;i++)
        {
            cin>>board[i];
        }

        cout<<solve(n,k,board)<<endl;
    }

    return 0;
    
}
