#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void countOccurance(std::vector<int>vec, int key){
    std::unordered_map<int, int>map;
    for(int i=0; i<vec.size(); i++){
        map[vec[i]]++;
    }
    if(map.find(key) != map.end()){
        cout<<"element found "<<map[key]<<" no of time"<<endl;
    }
}

int main(){
    std::vector<int>vec{1,2,3,4,4,4,4,4,4,4,4,4,4,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9};
    countOccurance(vec, 4);
    return 0;
}
