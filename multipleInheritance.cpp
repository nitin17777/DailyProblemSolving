#include<iostream>
using namespace std;

class Human
{
    public:
    string color;

    public:
    void speak()
    {
        cout<<"Speaking " <<endl;

    }

};

class Animal
{
    public:
    int age = 5;
    int weight;

    public :
    void bark()
    {
        cout<<"Barking"<<endl;

    }
};



class Dog:public Animal
{

};

class GermanShephered: 
public Dog
{

};


//multiple inheritance
class Hybrid:
public Animal , public Human
{

};



int main()
{

    Hybrid h;
    h.speak();
    h.bark();



    return 0;

}