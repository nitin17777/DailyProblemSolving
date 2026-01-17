#include <bits/stdc++.h>
using namespace std;

int numRescueBoats(vector<int> &people, int limit)
{

    /*
    we have weight of people

    Return the min number of boats to carry every given person

    */

    int n = people.size();

    sort(people.begin(), people.end());

    int l = 0, r = n - 1, boats = 0;

    // Pairing heaviest person with lightest under limits -> AS this gives the highest chance of saving a boat
    while (l <= r)
    {
        if (people[l] + people[r] <= limit)
        {
            l++;
            r--;
        }

        else
            r--;

        boats++;
    }

    return boats;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> people = {1, 2};
    cout << numRescueBoats(people, 3) << endl;

    return 0;
}