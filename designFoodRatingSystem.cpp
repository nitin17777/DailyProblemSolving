#include <bits/stdc++.h>
using namespace std;

struct comp
{
    bool operator()(const pair<int, string> &a, const pair<int, string> &b)
        const
    {

        if (a.first != b.first)
            return a.first > b.first;
        return a.second > b.second;
    }
};

class FoodRatings
{
private:
    // To map food to cuisine
    unordered_map<string, string> foodToCuisine;

    // To map food to it's rating
    unordered_map<string, int> foodToRating;

    // For each cuisine maintaing  a max heap of food
    // each element is (-rating ,foodName)

    unordered_map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, comp>> cuisineToFoods;

public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        int n = foods.size();

        for (int i = 0; i < n; i++)
        {
            // Store cuisine for this food
            foodToCuisine[foods[i]] = cuisines[i];

            // Storing current rating of this food
            foodToRating[foods[i]] = ratings[i];

            // Pushing into heap for its cuisine
            // ANd using

            cuisineToFoods[cuisines[i]].push({ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating)
    {
        // finding cuisine  of this given food
        string cuisine = foodToCuisine[food];

        // update new rating
        foodToRating[food] = newRating;

        // push new pair into cusinine's heap

        cuisineToFoods[cuisine].push({newRating, food});
    }

    string highestRated(string cuisine)
    {
        auto &pq = cuisineToFoods[cuisine];

        while (!pq.empty())
        {
            auto top = pq.top();
            int rating = top.first;
            string food = top.second;

            if (foodToRating[food] == rating)
                return food;

            pq.pop();
        }
        return "";
    }
};

int main()
{
    vector<string> foods = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> cuisine = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};

    vector<int> ratings = {9, 12, 8, 15, 14, 7};
}
