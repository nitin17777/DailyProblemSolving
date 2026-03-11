#include<bits/stdc++.h>
using namespace std;

//More cleaner approach using pure bit manipulation and not using extra string
int bitwiseComplement(int n)
{
    if(n==0)return 1;

    int mask = 0;
    int temp = n;

    //Building mask of length n having all 1s
    while(temp > 0)
    {
        mask = (mask << 1)|1;//Adding a '1' bit

        temp = temp >> 1;
    }

    return mask ^ n; //XOR : Will give 0 if same bits else 1 if both bits are different -> AS we need to find the complement

}

/*
int bitwiseComplement(int n)
{
    if(n==0)return 1;
    string s = bitset<32>(n).to_string();

    s.erase(0,s.find_first_not_of('0'));

    string comp = "";
    for(auto& x:s)
    {
        if(x == '1')comp+='0';
        else comp+='1';
    }

    int ans = stoi(comp,nullptr,2);
    return ans;
}
    */


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<bitwiseComplement(5)<<endl;

    return 0;
}