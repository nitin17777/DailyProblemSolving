z#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
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


        //Next m lines contains dimensions of box 

        /*
        side of ith cube = fi = ith fibonacci number


        m empty boxes are there
        Rules: 
        1-> Side of the box is parallel to side of the cube
        2-> NO larger cube on top of smaller one
        3-> Each box either on the bottom or top of other cubes such that all the space is occupied

        ith char = 1 if all n cubes can fit into ith box



        To fit two largest cubes it is sufficient that all side of the box are atleast fn and lartger of the sides of box is fn+1
        

        
        */



    
    }

    return 0;
}