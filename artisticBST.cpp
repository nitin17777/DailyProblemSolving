#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(vector<int>&a,vector<int>&b)
{
    int n = a.size(), m = b.size();

    ll sum = accumulate(a.begin(),a.end(),0LL);


    //find the sum of unmarked elements 

    /*
    Steps: choose a pivot and rotate a certain length and then mark the element a[b[i]] as visited, we can do m such operations and at last find the min possible sum of unmarked elements

    */

    //making arrays of even and odd index elements
    vector<int>even,odd;
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0) even.push_back(a[i]);
        else odd.push_back(a[i]);
    }

    sort(even.rbegin(),even.rend());
    sort(odd.rbegin(),odd.rend());


    //Pointers -> Tracks next largest available element
    // Marks-> Track how many times we have marked from theat group

    int evenPtr = 0,oddPtr = 0;
    int evenMarks = 0,oddMarks = 0;

    for(auto&x:b)
    {
        x--;//for 0 indexing

        if(x%2 == 0)
        {
            //if still element is there + element is postive or no mark is done yet
            if(evenPtr < even.size() && (even[evenPtr] > 0 || evenMarks == 0))
            {
                sum -=even[evenPtr];
                evenPtr++;
                evenMarks++;
            }
        }
        else
        {
            if(oddPtr < odd.size() && (odd[oddPtr] > 0 || oddMarks ==0))
            {
                sum-=odd[oddPtr];
                oddPtr++;
                oddMarks++;
            }
        }
    }

    return sum;//Remaining sum after removal
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,m;
        cin>>n>>m;

        vector<int>a(n),b(m);

        for(auto & x:a)cin>>x;
        for(auto & x:b)cin>>x;

        cout<<solve(a,b)<<endl;
    }

    return 0;
}