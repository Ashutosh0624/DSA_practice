#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{
    vector<int>vec{1,-2,3,-4,5};
    int currSum = 0;
    int maxSum = INT_MIN;
    for(int i = 0; i<vec.size(); i++){
        currSum = vec.at(i);
        maxSum = max(currSum, maxSum);
        if(currSum<0){
            currSum = 0;
        }
    }
    cout<<"Max Sub array Sum : "<<maxSum<<endl;
    return 0;
}