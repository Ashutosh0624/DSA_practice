// Bubble sort 
#include<iostream>
#include<vector>
using namespace std;

vector<int> bubbleSort(vector<int> &vec){
    // for loop for number of passes
    for(int i = 0; i<vec.size()-1; i++){
        for(int j= 0; j<vec.size()-1-i; j++){
            if (vec[j] > vec[j+1]){
                swap(vec[j], vec[j+1]);
            }
        }
    }
    return vec;
}
vector<int> insertionSort(vector<int>&vec){
    // designed for sorting list 
    for(int i =1; i<vec.size(); i++){
        int j = i;
        while(j>0 && vec[j-1] > vec[j]){
            swap(vec[j-1], vec[j]);
            j--;
        }
    }
    return vec;
}
vector<int> selectionSort(vector<int>&vec){
    for(int i =0; i<vec.size()-1; i++){
        for(int j=i, k=i; j<vec.size(); j++){
            if(vec[j] < vec[k]){
                k = j;
            }
            swap(vec[i], vec[k]);
        }
    }
    
    return vec;
}
int main() {
    vector<int>vec{12, 67, -3, -1, 8, 45, 100};
    vector<int>vec2 = bubbleSort(vec);
    for(int x: vec2){
        cout<<x<<" ";
    }
    return 0;
}