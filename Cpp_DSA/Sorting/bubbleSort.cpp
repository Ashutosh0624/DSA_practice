#include<iostream>
#include<vector>
using namespace std;
vector<int> bubbleSort(vector<int>vec){
    for(int i = 0; i<vec.size(); i++){
        for(int j = i+1; j<vec.size(); j++){
            if(vec[i] > vec[j]){
                swap(vec[i], vec[j]);
            }
        }
    }
    return vec;
}
int main(){
    vector<int>vec{3,2,1,5,6,4};
    vector<int>vec2;
    vec2 = bubbleSort(vec);
    for(auto &x: vec2){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}