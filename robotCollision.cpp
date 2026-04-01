#include<bits/stdc++.h>
using namespace std;


vector<int> survivedRobotsHealths(vector<int>& posi, vector<int>& health, string dir)
{


    /*

    All start moving on line at the same speed in their directions and if two robots ever share same posi ->they will collide ->  And the robot with lower health will be removed and health of other decreases by one

    If both have same health -> Then both are removed


    Return the health of robots that survived the collision
    
    
    */

    int n = posi.size();

    vector<tuple<int,int,char,int>>arr;


    //Combined all these 3 parameters of each robot

    for(int i = 0;i<n;i++)
    {
        arr.push_back({posi[i],health[i],dir[i],i});
    }


    //Sort on the basis of position, no need of comparator as it sorts on the basis of first value at default
    sort(arr.begin(),arr.end());

    stack <int>st;

    vector<int>currHealth(n);
    for(int i =0;i<n;i++)
    {
        currHealth[i] = get<1>(arr[i]);
    }

    for(int i =0;i<n;i++)
    {
        char d = get<2>(arr[i]);

        if(d == 'R')st.push(i);


        //now encountered 'L'
        else
        {
            while(!st.empty() && currHealth[i] > 0)
            {
                int j = st.top();

                if(currHealth[j] < currHealth[i])
                {
                    st.pop();//one with the lower health will be removed
                    currHealth[i]--;//And other's health will be decreased by one
                }

                
                else if(currHealth[j] > currHealth[i])
                {
                    currHealth[j]--;
                    currHealth[i] = 0;
                }


                //Remove both when they have same health 
                else
                {
                    currHealth[j] =0;
                    currHealth[i] =0;
                    st.pop();
                }
            }
        }
    }


    //Collecting all the survivors now
    vector<int>res(n,0);

    for(int i =0 ; i<n;i++)
    {
        if(currHealth[i] > 0)
        {
            int originalIdx = get<3>(arr[i]);
            res[originalIdx] = currHealth[i];
        }
    }

    vector<int>ans;
    for(auto & x:res)
    {
        if(x>0)
        {
            ans.push_back(x);
        }
    }
    return ans;
}
      

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>p = {5,4,3,2,1}, h = {2,17,9,15,10};
    string s = "RRRRR";

    vector<int>ans = survivedRobotsHealths(p,h,s);
    for(auto & x:ans)cout<<x<<" ";

    cout<<endl;

    return 0;
}