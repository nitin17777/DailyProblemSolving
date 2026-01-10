#include <bits/stdc++.h>
using namespace std;

struct Employee
{
    int id;
    int importance;
    vector<int> subordinates;
};

int getImportance(vector<Employee *> employees, int id)
{
    /*
    We are given id, we have to return the total importance value of this employee and all their direct indirect subordinates
    */

    // Creating map first of emp id so as tot access the employee directly with their id

    unordered_map<int, Employee *> mp;
    for (auto e : employees)
    {
        mp[e->id] = e;
    }

    // starting bfs now

    queue<int> q;
    q.push(id);

    int total = 0;

    // Each time we process an employee, we add their importance value and push their subordinates

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        Employee *emp = mp[curr];
        total += emp->importance;

        for (int sub : emp->subordinates)
        {
            q.push(sub);
        }
    }
    return total;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Employee *e1 = new Employee{1, 5, {2, 3}};
    Employee *e2 = new Employee{2, 3, {}};
    Employee *e3 = new Employee{3, 3, {}};

    vector<Employee *> emp = {e1, e2, e3};

    cout << getImportance(emp, 1) << endl;
    return 0;
}