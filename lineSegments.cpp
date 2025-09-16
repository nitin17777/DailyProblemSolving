#include<iostream>
#include<vector>
#include<numeric>
#include<cmath>
using namespace std;

bool isPossible(int px,int py,int qx, int qy, const vector<int>&a)
{

    /*
    we start at starting point px ,py and will perform n operations, 
    
    in ith operation we must choose any point such that Euclidean distance between current position and the point is exactly ai and then move to that point 
    
    we have to determine if it is possible to reach the terminal point qx qy after performing all operaations



    Yes if : sum of all 'a' >= distance && abs(distance -sum) is even,so that we wont be sort of just one movement 
    */
    

    double D = sqrt(pow(qx -px ,2) + pow(qy - py, 2));

    double S = accumulate(a.begin(), a.end(),0.0);

    if(S<D)return false;

    double diff = S - D;
    //if(dif %2 != 0)return false; --> Cant use this with double and float

    if(fmod(diff,2.0) > 1e-8) // used to check if diff is even or odd
    return false;

    return true;
}

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int px, py, qx, qy;
        cin >> px >> py >> qx >> qy;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        cout << (isPossible(px, py, qx, qy, a) ? "YES" : "NO") <<endl;
    }

    return 0;
}


