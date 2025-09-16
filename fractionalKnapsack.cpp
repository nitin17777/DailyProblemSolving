#include<iostream>
#include<vector>
using namespace std;


bool cmp(pair<double,item>a ,pair<double,item>b)
{
    return a.first > b.first;

}


double fractionalKnapSack(int W,vector<int>item, int n)
{
    vector<pair<double,item>> v;
    for(int i = 0; i< n ; i++)
    {
        for(int i = 0; i < n; i++)
        {
            doublePerUnitValue = (1.0 * arr[i].value) / arr[i].weight;

            pair<double,item>p = make_pair(perUnitValue, arr[i]);
            v.push_back(p);
        }
        sort(v.begin(), v.end());

        int totalValue = 0;
        for(int i = 0; i <n; i++)
        {
            if(v[i]. second.weight > W)
            {
                //so we can only include fraction values
                totalValue += W *v[i].first;
                W = 0;
            }
            else
            {
                totalValue += v[i].second.value;
                W = W - v[i].second.weight;


            }
        }

    }


}

int main()
{
    return 0;

}