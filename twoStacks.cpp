#include<iostream>
#include<stack>
using namespace std;



class TwoStack
{
    int * arr;
    int top1;
    int top2;
    int size;



public:

//constructor
TwoStack(int s)
{
    this ->size = s;
    top1 = -1;
    top2 =s;

    arr = new int[s];
}

    
    //push in stack 1
    void push1(int num)
    {

        //atleast one empty is present wala case
        if(top2 - top1 > 1)
        {
            top1++;
            arr[top1] = num;
        }

        else
        {
            cout<<"Stack Overflow."<<endl;
        }
    }

    //push in stack 2
    void push2(int num)
    {

        if(top2 - top1 > 1)
        {
            top2--;
            arr[top2] = num;

        }
        else
        {
            cout<<"Stack Overflow."<<endl;
        }
    }


    int pop1()
    {
        if(top1>=0)
        {
            int ans= arr[top1];

            top1--;
            return ans;


        }
        else
        {
            return -1;

        }
    }


    int pop2()
    {
        if(top2<size)
        {
            int ans= arr[top2];
            top2++;
            return ans;
        }
        else
        {
            return -1;    
        }
    }


//destructor
~TwoStack()
{
    delete[] arr;
}

};


int main()
{

    TwoStack ts(5);
    ts.push1(10);
    ts.push2(20);
    ts.push1(43);
    ts.push2(91);


    cout<<ts.pop1()<<endl;
    cout<<ts.pop2()<<endl;


    return 0;

}