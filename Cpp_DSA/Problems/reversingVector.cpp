#include<iostream>
#include<vector>
using namespace std;
int main(){
    // Brute force method, time complexity = o(n)
    vector<int>vec{1,2,3,4,5,6,7,8};
    int n = vec.size();
    int maxSum = INT32_MIN;
    for(int st = 0; st<n; st++){
         int currSum = 0;
        for(int end = st; end<n; end++){
            currSum += vec[end];
            maxSum  = max(currSum, maxSum);
            }
        }
        cout<<maxSum;
    return 0;

}