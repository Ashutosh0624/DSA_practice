#include<iostream>
#include<vector>
using namespace std;
vector<int> selectionSort(vector<int> &vec){
    for(int i = 0; i<vec.size()-1; i++){
        for(int j=i,k=i; j<vec.size(); j++){
              if(vec[j] < vec[k]){
                k = j;
              }
              swap(vec[i], vec[k]);
        }
    }
    return vec;
}
int main(){
    vector<int>vec{11,13,7,2,6,9,4,5,10,3};
    vector<int>vec2;
    vec2 = selectionSort(vec);
    for(int x:vec2){
        cout<<x<<" ";
    }
    return 0;

}