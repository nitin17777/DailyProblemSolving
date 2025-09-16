#include<iostream>
#include<vector>

using namespace std;

int maxPeak(vector<int>weather,int k)
{
    //every element of weather describes weather on i'th day , if it rains: 1 else if day is good : 0

    //one hike to peak takes exactly k days and during these days weather must be good + after each hike there should be a gap of one day atleast , now we need to find the maximum number fo hike  we can visit

    //check the weather condition for travelTime days

    int n = weather.size();
    int canCover = 0;

    int i = 0;

    while(i+k <= n)
    {
        bool allClear = true;//assuming next 'k' days are clear

        //checking if next k days are all good
        for(int j = 0; j<k; j++)
        {
            if(weather[i+j] ==1) 
            {
                //if weather is not good
            
            allClear=false;
            break;
            }
        }
            if(allClear)
            {
                canCover++; //then skip k days + 1 rest day
                i+=k+1;
            }

            else
            i++; //move forward to check others
              
    }
    
    return canCover;

    
}

int main()
{

    int t; //test cases
    cin>>t;

    while(t--)
    {
        int n , k;

        cin>>n>>k;


        vector<int>weather(n);


        for(int i = 0;i<n;i++)
        {
            cin>>weather[i];
        }

        int result = maxPeak(weather,k);

        cout<<result<<endl;

    }
    
    
    return 0;
    
}
