#include<iostream>
#include<deque>

using namespace std;

int main()
{
    deque<int>d;

d.push_back(1);
d.push_front(2);
d.push_front(5);


for(int i :d)
{
    cout<<i<<" ";}



cout<<"Print element at 1st index: "<<d.at(0)<<endl;

    
    cout<<d.at(2)<<endl;
    cout<<d.at(1)<<endl;

    cout<<"Before erase: "<<d.size()<<endl;

    d.erase(d.begin(),d.begin()+1);

    cout<<"After erase: "<<d.size()<<endl;

}