#include<bits/stdc++.h>
using namespace std;

long long mostPoints(vector<vector<int>>& questions)
{
    int n = questions.size();

    //questions[i] = [points,brainpower]

    //for each question we solved we get assigned points to it and we have to skp the number of questions which are there in second place of 2d array element


    // algo can be that go to the element of 2d array, count the marks associated with it ,store and then skip the no.of questions associated with it and do the same for that element also , continue till the array ends
    //then iterate over the entire elements of 2d array in similar manner and then at last find the max of every count


    vector<long long>dp(n+1, 0); // (size,initiallization)


    //count first
    for(int i = n-1; i >= 0; i--)
    {
        int points = questions[i][0];
        int skip = questions[i][1];

        long long solve;


        if(i + skip + 1 < n)
        {
            solve = points + dp[i + 1 + skip];

        }
        else
        {
            solve = points;
        }

        long long skipQuestion = dp[i+1];


        dp[i] = max(solve,skipQuestion); //max of : if question is solved and if question is skipped
    }

    return dp[0];
}


int main()
{

    vector<vector<int>>arr = {
        {3,2}, {4,3}, {4,4},{2,5}
    };

    long long ans = mostPoints(arr);


    cout<<ans<<endl;

    return 0;;

}