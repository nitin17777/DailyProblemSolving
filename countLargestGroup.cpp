#include<iostream>
#include<unordered_map>
using namespace std;

int countLargestGroup(int n)
{
    // we have to find the number of groups that have largest size
    //each number is grouped  qccording to the sum of it's digits

    unordered_map<int,int>digitSumCount;

    for(int i = 1; i<=n; i++)
    {
        int sum = 0, num = i;
        while(num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        digitSumCount[sum]++;
    }

    int maxSize = 0;
    for(auto & entry : digitSumCount)
    {
        maxSize = max(maxSize,entry.second);
    }
}

int main()
{

    int n = 13;
    int ans = countLargestGroup(n);

    cout<<ans<<endl;

    return 0;

}