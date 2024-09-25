#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
    map<int, int>mpp;

    map<int, pair<int, int>>mpp2;

    map< pair<int, int>, int>mpp3;


    mpp[1] = 2;
    mpp.insert({2, 4});

    for(auto it: mpp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;

}