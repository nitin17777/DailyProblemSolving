#include <bits/stdc++.h>
using namespace std;

int compareVersion(string version1, string version2)
{

    // If version1 < version2, return -1.
    // If version1 > version2, return 1.
    // otherwise return 0

    vector<int> v1, v2;

    string s;

    auto split = [](const string &version)
    {
        vector<int> parts;
        stringstream ss(version);
        string token;

        while (getline(ss, token, '.'))
        {
            parts.push_back(stoi(token));
        }
        return parts;
    };

    v1 = split(version1);
    v2 = split(version2);

    int n = max(v1.size(), v2.size());
    v1.resize(n, 0); // pad with 0
    v2.resize(n, 0); // pad with 0

    for (int i = 0; i < n; i++)
    {
        if (v1[i] < v2[i])
            return -1;
        if (v1[i] > v2[i])
            return 1;
    }

    return 0;
}

int main()
{
    cout << (compareVersion("1.2", "1.10") ? 1 : -1) << endl;

    return 0;
}