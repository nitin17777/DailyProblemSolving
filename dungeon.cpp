#include <bits/stdc++.h>
using namespace std;

int maxMonsters(vector<int> &a, vector<int> &b, vector<int> &c)
{
    /*
    //n swords facing m monsters

    //damage of ith sword is ai => value of ith monster is bi
    //Can kill if  damage(x) is greater than equal to life of monster(y)

    //if ci > 0 => we will obtain new sword with damage = max(x, ci)

    //Return max number of mosnters you can kill

    int count = 0;

    for(int  i = 0;i<b.size();i++)
    {

        int x = a[i];
        int y = b[i];

        if(x > y)count++;

        x = max(x,c[i]);//for newx loop





        //and now new damage = max(x,ci)






    }
    return count;
    */

    // It wold be better to use the sword for monsters with ci = 0 at end as they wont help us in any future attack

    // Stage 1 would be for monsters for ci > 0 and another stage for monster with ci == 0
}

void solve()
{
    int n;
    cin >> n;
}

int main()
{
    vector<int> a = {2, 2, 2};
    vector<int> b = {2, 3};
    vector<int> c = {3, 2};

    cout << maxMonsters(a, b, c) < endl;

    return 0;
}
