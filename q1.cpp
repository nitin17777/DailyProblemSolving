#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item with value and weight
struct Item
{
    int value;
    int weight;
};

// Comparator function to sort items by their value/weight ratio in descending order
bool compareItems(Item a, Item b)
{
    double ratio1 = (double)a.value / (double)a.weight;
    double ratio2 = (double)b.value / (double)b.weight;
    return ratio1 > ratio2;
}

int main()
{
    int n;

    // Match the requested input format from the sample test cases
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter value and weight for each item:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].value >> items[i].weight;
    }

    int capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // Sort items based on highest value-to-weight ratio
    sort(items.begin(), items.end(), compareItems);

    double maxValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++)
    {
        // If adding the whole item doesn't exceed capacity, take the whole item
        if (currentWeight + items[i].weight <= capacity)
        {
            currentWeight += items[i].weight;
            maxValue += items[i].value;
        }
        // If we can't take the whole item, take the remaining fractional part
        else
        {
            int remainingCapacity = capacity - currentWeight;
            // Add fraction of the item's value
            maxValue += items[i].value * ((double)remainingCapacity / items[i].weight);
            break; // The knapsack is now exactly full
        }
    }

    // Output the result matching the sample format
    cout << "Maximum Value: " << maxValue << endl;

    return 0;
}