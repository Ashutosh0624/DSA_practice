#include<iostream>
using namespace std;
void swapNos(int &a, int &b){
    a = a^b;
    b = a^b;
    a = a^b;
}
// check ith bit is set or not
// can be done by using and or left shift or right shift operator
bool checkKthBit(int  n, int k){
    if(k>=7){
        cout<<"bis is out of index"<<endl;
    }
    int mask = 1<<k;
    int res  = n & mask;
    if(res == 1<<k){
        return true;
    }
    else{
        return false;
    }
}

int extractkthBit(int n, int k){
    int mask = 1<<k;
    int res = n & mask;
    return (res >> k);
}
int  setkthBit(int num, int i){
    return (num | 1<<i);
}

int clearkthBit(int num, int k){
    return (num & (~(1<<k)));
}

int togglekthbit(int num, int k){
    return (num ^ (1<<k));
}

int main(){
    int a{9};
    int k = 0;
    bool res = checkKthBit(a, k);
    cout<<res<<endl;

    int ibit = extractkthBit(a, 1);
    cout<<ibit<<endl;
    return 0;
}