#include <bits/stdc++.h>
using namespace std;

int videoStitching(vector<vector<int>> &clips, int time)
{
    /*
    Sporting event lasted time seconds

    Video clips can be overlapping with each other ahs varying length

    clips[i] = start[i], end[i]

    Return the min number of clips needed so that we can cut the clips into segments that covers the entire sporting time [0,time]

    if task is impossible return -1;

    */

    int n = clips.size();

    int clipsUsed = 0, currEnd = 0, farthest = 0, i = 0;

    sort(clips.begin(), clips.end());

    while (currEnd < time)
    {
        while (i < n && clips[i][0] <= currEnd)
        {
            farthest = max(farthest, clips[i][1]);
            i++;
        }

        if (farthest == currEnd)
            return -1;

        clipsUsed++;
        currEnd = farthest;
    }
    return clipsUsed;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> clips = {{0, 2}, {4, 6}, {8, 10}, {1, 9}, {1, 5}, {5, 9}};

    cout << videoStitching(clips, 10) << endl;

    return 0;
}