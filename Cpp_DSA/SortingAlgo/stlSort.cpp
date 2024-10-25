#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>vec {10, 20, 5,7};

    sort(vec.begin(), vec.end()); // sorting in ascending order
    for(int x: vec){
        cout<<x<<" ";
    }
    cout<<endl;
    sort(vec.begin(), vec.end(), greater<int>());
    for(int x: vec){
        cout<<x<<" ";
    }
    return 0;
    
}