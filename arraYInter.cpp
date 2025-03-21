#include<iostream>
#include <vector>
#include<climits>
using namespace std;


vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)


{
    vector <int>ans;
    int i = 0, j = 0;
    while(i<n && j <m)
    {
        if (arr1[i] == arr2[j])
        {

        ans.push_back(arr1[i]);

        i++;
        j++;

        }
        else if (arr1[i]<arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return ans;

}
int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5}; // Example array 1
    vector<int> arr2 = {3, 4, 5, 6, 7}; // Example array 2

    int n = arr1.size(); // Size of array 1
    int m = arr2.size(); // Size of array 2

    vector<int> result = findArrayIntersection(arr1, n, arr2, m);

    // Output the intersection
    cout << "Intersection: ";
    for (int val : result)
    {
        cout << val << " ";
    }

    return 0;
}
