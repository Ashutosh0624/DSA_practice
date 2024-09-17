#include<iostream>
#include<vector>
using namespace std;
vector<int> insertion_sort(vector<int>&vec){
    for(int i = 1; i<vec.size(); i++){
        int j = i;
        while(j>0 && vec[j-1] > vec[j]){
            swap(vec[j-1], vec[j]);
            j--;
        }
    }
    return vec;
}
int main(){
    vector<int>vec{6,5,4,3,2,1};
    vector<int>vec2;
    vec2 = insertion_sort(vec);
    for(int x: vec2){
        cout<<x<<" ";
    }
    return 0;
}