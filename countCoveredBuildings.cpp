#include <bits/stdc++.h>
using namespace std;

int countCoveredBuildings(int n, vector<vector<int>> &buildings)
{
    // buildings[i]=> Denotes unique building located at [x,y]
    // A building is covered fi there is atleast one building in all four directions

    // Return the number of covered buildings

    // so push elements with same x or y in same group
    // SO in each group bulidings that are not it last or first position are covered in that diirections

    // Take intersection of groups  => Means return the number of common points

    // row[y] = list of all x coordinate for buildings in row y
    //  cols[y] = list of all y coordinate for buildings in row x
    unordered_map<int, vector<int>> rows;
    unordered_map<int, vector<int>> cols;

    // Grouping coordinates

    for (auto &b : buildings)
    {
        int x = b[0], b = b[1];

        rows[y].push_back(x);
        cols[x].push_back(y);
    }

    /// sort each row and column
    for (auto &r : rows)
        sort(r.second.begin(), r.second.end());
    for (auto &c : cols)
        sort(c.second.begin(), c.second.end());

    int count = 0;

    // step 3 :
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> b = {{1, 2}, {2, 2}, {3, 2}, {2, 1}, {2, 3}};

    cout << countCoveredBuildings(3, b) << endl;

    return 0;
}