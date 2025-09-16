#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<string> removeSubfolders(vector<string>& folder)
{
    //we have to return the folder after removing all sub folders in those folders

    //1->sort the list so that they would appear lexicographically
    sort(folder.begin(),folder.end());




    //2->Loop through it and for each folder we have to keep if it's not a subfolder of last added folder

    vector<string>result;

    //now if result array is empty or last inserted folder is not parent of this folder insert it into the result array

    for(const string& f: folder)
    {
        if(result.empty() || f.find(result.back() + "/") !=0)
                //if(result.empty() || f.substr(0, result.back().size() + 1) != result.back() + "/")

        {
            result.push_back(f);
        }
    }
    return result;



}

int main()
{

    vector<string>folder = {"/a","/a/b","/c/d","/c/d/e","/c/f"};

    vector<string>ans = removeSubfolders(folder);

    for(const auto&an :ans)
    {
        cout<< an <<" ";
    }

    cout<<endl;


    return 0;
    
}
