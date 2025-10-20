#include <iostream>
#include <vector>

using namespace std;

int finalValueAfterOperations(vector<string> &operations)
{
    int ans = 0;

    for (auto str : operations)
    {
        if (str == "--X" || str == "X--")
        {
            ans--;
        }
        else if (str == "++X" || str == "X++")
        {
            ans++;
        }
    }
    return ans;
}

int main()
{
    vector<string> ops = {"--X", "X++", "X++"};
    cout << finalValueAfterOperations(ops) << endl;

    return 0;
}
