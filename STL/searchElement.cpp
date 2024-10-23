#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool searchElement(std::vector<int>arr, int key){
    unordered_map<int, int> map;
    for(int i = 0; i<arr.size(); i++){
        map[arr[i]] = i;
    }
    if(map.find(key) != map.end()){
          cout<<"Element found at index: "<<map[key]<<endl;
          return true;
    }
    cout<<"Element not found"<<endl;
    return false;

}

int main(){
    std::vector<int> arr = {1,2,3,4,5,6,7,8,9,10};

    int  key = 5;

    bool res = searchElement(arr, key);

    cout<<res<<endl;

    return 0;
}

