#include<iostream>
#include<vector>
using namespace std;


int main()
{
    vector<int> v;

    vector<int> a(5,1); //(size,initialise with)

    vector<int>last(a);
    cout<<"LAST:"<<endl;

    cout<<"Print a"<<endl;

    for (int i :a)
    {
        cout<<i<<" ";

    }

    cout<<"Capacity-> " <<v.capacity()<<endl;

    v.push_back(1);
    cout<<"Capacity-> " <<v.capacity()<<endl;

    v.push_back(2);
    cout<<"Capacity-> " <<v.capacity()<<endl;

    v.push_back(3);
    cout<<"Capacity-> " <<v.capacity()<<endl;

    cout<<"Size-> " <<v.size()<<endl;


    cout<<"Element at 2nd Index : "<< v.at(2)<<endl;


cout<<"Size before clear: "<<v.size()<<endl;
v.clear();
cout<<"Size after clear: "<< v.size()<<endl;
}