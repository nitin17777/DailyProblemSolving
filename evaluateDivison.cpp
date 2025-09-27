#include <iostream>
#include <vector>

using namespace std;

vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
}

int main()
{

    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};

    vector<double> values = {2.0, 3.0};

    vector<vector<string>> queries = {
        {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

    vector<double> ans = calcEquation(equations, values, queries);

    return 0;
}
