#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>vec{1,2,3,4,5,6};
    for(int i = 0; i<vec.size(); i++)
    {
        cout<<vec.at(i)<<" ";
    }
    return 0;
}