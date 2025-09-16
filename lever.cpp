#include<iostream>
#include<vector>

using namespace std;

int iterations(int n, vector<int>& a, vector<int>& b)
{
    int ans = 0;

    while(true)
    {
        bool dec = false,inc = false;

        for(int i =  0 ; i < n; i++)
        {
            if(a[i] > b[i] && !dec)
            {
                a[i]--;
                dec= true;
            }
        }

        for(int i = 0;i<n;i++)
        {
            if(a[i] < b[i] && !inc)
            {
                a[i]++;
                inc = true;
            }
        }
        ans++;
        if(!dec)break;
    }
    return ans;
}


int main()
{

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int>a(n),b(n);
        
        for(int i = 0;i <n;i++)
        {
            cin>>a[i];
        }
        for(int i = 0;i <n;i++)
        {
            cin>>b[i];
        }

        int ans= iterations(n,a,b);
        cout<<ans<<endl;
    }
}

    


    /*
    vector<int>a ={7,3};

    vector<int>b = {5,6};

    int n = 2;

    long long ans = iterations(n,a,b);

    cout<<ans<<endl;

    return 0;

    */



/*
long long iterations(int n, const vector<long long>& a, const vector<long long>& b) {
    long long steps = 0;
    for (int i = 0; i < n; i++) {
        steps += abs(a[i] - b[i]); // count aint adjustments (both increase and decrease)
    }
    return steps;
}

int iterations(int n , vector<int>&a, vector<int>&b)
{
    //choose a random index i such that ai >bi : Decrease ai by 1 ,and if no such is there ignore the step

    //choose random i such that ai<bi : increase ai by 1 and if no such i ignore the step

    //if step 1 is ignored, lever 1 wiint end the iteration

    int iterations = 0;
    for(int i = 0;i<a.size();i++)
    {
        if(a[i] > b[i])
        {
            a[i]-=1;

        }
        else

    }
    return iterations;



}

*/

