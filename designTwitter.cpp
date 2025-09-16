#include<bits/stdc++.h>
using namespace std;

class Twitter
{
    private:
    long long timeStamp;
    unordered_map<int,unordered_set>>follows;
    unordered_map<int,vector<pair<long long, int>>>tweets;


    public:
    Twitter()
    {
        timestamp = 0;

    }


    void postTweet(int userId, int tweetId)
    {
        tweets[userId]. push_back({timestamp++, tweetId})
    }

}

int main()
{

    int 
    return 0;
    
}
