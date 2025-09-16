#include<iostream>
#include<vector>

using namespace std;

int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets)
{
    int n = baskets.size();

    /*we have to place fruits according to following rules:
    
    */
   vector<bool>used(n,false);
   int unplaced = 0;

   for(int i=0; i<n; i++)
   {
        bool placed = false; // showing that current fruit is not yet placed

        for(int j=0; j<n; j++)
        {
            //if basket is not used and fruits[i] < baskets[j]
            if(used[j] && fruits[i] <= baskets[j])
            {
                placed =true;
                used[j] = true;
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
    vector<int>fruits = {4,2,5};
    vector<int>baskets = {3,5,4};
    int ans = numOfUnplacedFruits(fruits,baskets);

    cout<<ans<<endl;

    return 0;
    
}
