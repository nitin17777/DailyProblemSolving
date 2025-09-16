#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//surviveDays -> Days you need to survive
//canBuuy -> Maximum unit of food you can buy each day
//foodReq -> Unit of food required per day
int minDays(int surviveDays, int canBuy, int foodReq)
{
    int sunday = surviveDays/7;
    int ans = 0;
    int buyingDays = surviveDays - sunday;
    int totalFood = surviveDays * foodReq;

    if(totalFood % surviveDays == 0)
    {
        ans = totalFood / surviveDays;
    }
    else
    {
        ans = totalFood / surviveDays +1;
    }

    //this condition ensures that you have enough actual buying days to purchase the needed food(IMORTANT)
    if(ans <= buyingDays)
    {
        return ans;
    }
    else
    return -1;
 
}

int main()
{

    int S = 10;
    int N = 16;
    int M = 2;

    int ans = minDays(S,N,M);
    cout<<ans<<endl;
     

    return 0;

}
