#include <iostream>
#include <vector>

using namespace std;

int maxPossible(vector<int> &alice, vector<int> &bob)
{
    // they share atleast one game in common

    // alice begins by sharing her fav first
    // if bob likes the game , they play , else bob will suggest his fav

    // calculate max possible number of suggestion they will make before playing the game
    int a = alice.size();
    int b = bob.size();
    // since they will give all possible answers before their games matches

    return a + b - 1;
}

int main()
{

    vector<int> alice = {1, 2};
    vector<int> bob = {2, 3, 5};

    cout << maxPossible(alice, bob) << endl;

    return 0;
}
