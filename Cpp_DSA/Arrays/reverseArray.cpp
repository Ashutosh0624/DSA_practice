#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

std::vector<int> reverseArr(std::vector<int>&vec){
    for(int i=0, j=vec.size()-1; i<j; i++, j--){
        swap(vec[i], vec[j]);
    }
    return vec;
}
int main(){
    std::vector<int>vec{1,2,3,4,5,6};
    vec = reverseArr(vec);
    for(auto i: vec){
        cout<<i<<" ";
    }
    return 0;
}