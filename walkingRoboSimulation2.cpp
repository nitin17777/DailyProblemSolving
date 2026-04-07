#include<bits/stdc++.h>
using namespace std;

int w,h;
int x,y; //current position
int dir;


Robot(int width, int height) {
    w=width;
    h = height;
    x = 0;
    y=0;
    dir=0;  
    }
    
    void step(int num) {

        int peri = 2 *(w+h) - 4;
        if(peri == 0)return;

        //To reduce full cycles
        num = num % peri;

        //If num == 0, robot completes full cycle so direction should be South as per the question

        if(num == 0)
        {
            if(x == 0 && y == 0)dir = 3;
            
            return;
        }

        while(num--)
        {
            if(dir == 0)//Means east currently
            {
                //Move if it is possible to move
                if(x+1 < w)x++;

                else 
                {
                    dir = 1;
                    y++;
                }
            }

            else if(dir == 1)//North
            {
                if(y+1 < h)y++;

                else 
                {
                    //turn west
                    dir = 2;
                    x--;
                }
            }

            else if (dir == 2) { // West
                if (x - 1 >= 0) {
                    x--;
                } else {
                    dir = 3; // turn South
                    y--;
                }
            }
            else { // South
                if (y - 1 >= 0) {
                    y--;
                } else {
                    dir = 0; // turn East
                    x++;
                }
            }
            
        }
    }
    
    vector<int> getPos() {
        return {x,y};
        
    }
    
    string getDir() {

        if(dir ==0)return "East";
        if(dir == 1)return "North";
        if(dir == 2)return "West";
        return "South";        
    }

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}