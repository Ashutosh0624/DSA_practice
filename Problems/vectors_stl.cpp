#include<iostream>
#include<vector>
using namespace std;
int linearSearchVec(vector<int>&vec, int  key){
    int index = 0;
    for(int x:vec){
        if(x ==key){
            return (index);
        }
        index +=1;
    }
    return -1;
}
int main(){
    vector<int>vec{1,2,3,4,5,6};
    int key = 1;
    int index = linearSearchVec(vec, key);
    if(index != -1){
        cout<<"Key found at :"<<index<<endl;
    }
    else{
        cout<<"Key not found"<<endl;
    }
    return 0;
}
