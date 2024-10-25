#include<iostream>
#include<vector>
using namespace std;
int kthLargestElement(vector<int> &vec, int k){
    //bubble sort
    for(int i = 0; i<vec.size(); i++){
        for(int j = i+1; j<vec.size(); j++){
            if(vec[i] > vec[j]){
                swap(vec[i], vec[j]);
            }
        }
    }
    int kL = vec.size() - k;
    return vec[kL];
}
int main(){
    vector<int>vec{5, 10, -3, 99, 67, -6};
    int kL = kthLargestElement(vec, 2);
    cout<<kL<<endl;
    return 0 ;
}