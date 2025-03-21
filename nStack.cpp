#include<iostream>
using namespace std;

//implement N stacks in an array using a single array of size 'S'

class NStack
{
    int * arr; // array to store stack elements
    int* top; //  array to store top index of each stack
    int* next; //  array to store next available index or next element in stack
    int n,s; //number of stacks and size of array
    int freespot; // to keep track of next available free index

    public:
    //A constructor to initiallise N stracks in an array of size S
    NStack(int N,int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        //iniiallises all stacks as empty stack

        for(int i =0;i<n;i++)
        {
            top[i] = -1;
        }

        //initiallise next array for free slots
        for(int i = 0;i<s;i++)
        {
            next[i] = i+1;
        }

        //mark last index as the end of free slots
        next[s-1] = -1;

        //initiallise freespot
        freespot = 0;
    }


//function to push an element into mth stack
        bool push(int x,int m)
        {
            if(freespot == -1)

            {
                return false;

            }
            //find index to insert element
            int index= freespot;

            //update freespot
            freespot = next[index];

            //insert element into array
            arr[index] = x;

            //update next
            next[index] = top[m-1];


            //update top
            top[m-1] = index;
            return true;
        }
    //pops top element from mth stack //->>>just reverse the push function

        int pop(int m)
        {
            if(top[m-1] == -1)
            {
                return -1;
            }
            int index = top[m-1];

            top[m-1] = index;
            
            next[index] = freespot;

            freespot = index;
            
            return arr[index];

        }
    };


int main()
{
    NStack stacks(3,10); // 3 stacks in an array of sixe 10
    
    stacks.push(15,1);
    stacks.push(45,2);
    stacks.push(30,1);
    stacks.push(25,3);

    cout << "Popped from stack 1: " << stacks.pop(1) << endl; // Should return 30
    cout << "Popped from stack 2: " << stacks.pop(2) << endl; // Should return 45
    cout << "Popped from stack 3: " << stacks.pop(3) << endl; // Should return 25

    return 0;

}

