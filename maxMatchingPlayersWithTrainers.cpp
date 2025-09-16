#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers)
{
    //players[i] represents the ability of ith player
    //trainers[j] represents the training capacity jth trainer

    //ith player can match the jth trainer if player's ability is less than or equal to the trainer's training capacity

    //one player can be matched with atmost one trainer

    //return the max matchings between players and trainers that satisfy these conditions

    sort(trainers.begin(),trainers.end());
    sort(players.begin(),players.end());


    int count = 0;

    for(int i = 0;i<players.size();i++)
    {
        for(int j = 0;j<trainers.size();j++)
        {
            if(players[i] <= trainers[j])
            {
                count++;
                trainers.erase(trainers.begin()+ j);
               players.erase(players.begin()+ i);

                

            }

        }
    }

    return count;


}



int main()
{
    vector<int>players = {4,7,9};
    vector<int>trainers = {8,2,5,8};

    int ans = matchPlayersAndTrainers(players,trainers);

    cout<<ans<<endl;
    return 0;
    
}
