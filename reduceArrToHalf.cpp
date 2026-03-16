#include<bits/stdc++.h>
using namespace std;

int minSetSize(vector<int>& a)
{
    int n = a.size();

    //We can choose a set of integers and remove all the occurences

    //Return the min size of the set so that at least half of the integers of the array are removed


    //pair the number and it's frequency

    // Then push each pair into priority queue

    //And start deleting from the top

    unordered_map<int,int>freq;
    for(auto & x:a)freq[x]++;

    priority_queue<int>pq;

    for(auto& x:freq)pq.push(x.second);

    int removed = 0;
    int count = 0;


    while(removed < n/2)
    {
        removed += pq.top();
        pq.pop();
        count++;
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>a = {3,3,3,3,5,5,5,2,2,7};
    cout<<minSetSize(a)<<endl;

    return 0;
}