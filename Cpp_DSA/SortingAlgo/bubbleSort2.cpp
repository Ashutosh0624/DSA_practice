#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> sortArray(vector<int>&vec){
    bool swapped;  // making bubble sort as adaptive
    //Implementation of bubble sort on a vector 
    for(int i = 0; i<vec.size() - 1; i++) {
        swapped = false;
        // for n elements, number of passes = n-1
        for(int j=0; j<vec.size()-1-i; j++){
            // in every iteration/pass the comparision will reduce 
            if(vec[j] > vec[j+1]){
                swap(vec[j], vec[j+1]);
                swapped = true;
            }
        }
        // if no swaps were made, the array is already sorted, hence bubble sort is adaptive as there are no changes if the list is alrady sorted.
        // Adaptive : if the list is already sorted then sorting should take minimum time. 
        if(!swapped){
            break;
        }
}   
    return vec;
} 

int main(){
    vector<int>vec{12, -9, 5, 34, 20, 10};
    vector<int>vec2;
    vec2 =  sortArray(vec);
    for(int x: vec2){
        cout<<x<<" ";
    }
    return 0;
}