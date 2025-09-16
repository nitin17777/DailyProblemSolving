#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


//Memoisation map to store alredy computed probabilities
unordered_map<long long ,double>memo;

long long encodeKey(int a, int b)//To pack both a and b as just one digit since unordered_map can take a single key only

{
    return ((long long)a << 32) | b;
}


double dfs(int a ,int b)
{

    //Base cases
    if(a<=0 && b<=0)return 0.5;
    if(a<=0 && b>0)return 1.0;
    if(a>0 && b<=0)return 0.0;


    long long key = encodeKey(a,b);

    if(memo.count(key)) 
    return memo[key];

    double ans = 0.25 *dfs(a-4,b)
                +0.25 * dfs(a-3,b-1)
                +0.25 * dfs(a-2,b-2)
                +0.25 * dfs(a-1,b-3);

                memo[key] = ans;
                return ans;    
}

double soupServings(int n)
{

    //n = Starting ml of both A and B

    //at a time one of the four servings are chosen at random each with equal probability of 0.25 independent of all previous turns


    //amounts of A and b are poured simultaneously during the turn 

    //processs is stopped immediately after any one of the soups are used up

    //we have to find: P(A empty first) + 0.5 × P(A and B empty in same turn)


    if(n >= 4800)return 1; //since for large n , probability tends to 1

    int scaledN = (n+24)/25;
    return dfs(scaledN,scaledN);


} 

int main()
{

    int n = 51;

    double ans = soupServings(n);

    cout<<ans<<endl;

    return 0;
    
}
