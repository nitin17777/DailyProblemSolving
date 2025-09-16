#include<iostream>
#include<vector>

using namespace std;

int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets)
{
    int n = fruits.size();
    ///each fruit must be placed in the leftmost basket with capacity greater than or equal to quantity of that fruit

    //we have to count the number of unplaced fruits

    //by binary search find the just greatest number available in basket

    int unplaced = 0;
    vector<bool>used(n,false);

    for(int i = 0; i < n; i++)
    {
        bool placed = false;

        for(int j =0;j < n ;j++)
        {
            if(!used[j] && baskets[j] >= fruits[i])
            {
                used[j] = true;
                placed = true;
                break;
            }
        }

        if(!placed)
        {
            unplaced++;
        }
    }
    return unplaced;   
}

int main()
{
    vector<int>fruits={4,2,5};
    vector<int>baskets={3,5,4};

    int ans =numOfUnplacedFruits(fruits,baskets);

    cout<<ans<<endl;
    
    return 0;

}
