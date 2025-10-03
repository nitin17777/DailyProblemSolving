#include <iostream>
#include <unordered_set>

using namespace std;

void decide(string str)
{

    unordered_set<char> chars;
    for (auto &ch : str)
    {
        chars.insert(ch);
    }
    int n = chars.size();

    if (n % 2 != 0)
    {
        cout << "IGNORE HIM!" << endl;
    }
    else
    {
        cout << "CHAT WITH HER!" << endl;
    }
}

int main()
{

    string str;
    cin >> str;

    decide(str);
    return 0;
}
