#include<iostream>
#include<vector>
using namespace std;

int arrSum(int *arr, int n){
    std::vector<int>dp(n+1);
    dp[0] = arr[0];
    dp[1] = dp[0] + arr[1];

    for(int i=2; i<=n-1; i++){
        dp[i] = dp[i-1] + arr[i];
    }

    return  dp[n-1];
}

// method 2  : using recursion

int sumArr(int *Arr, int n){
    if(n==1) return Arr[0];

    if (n == 0) return 0;

    return  sumArr(Arr + 1, n-1) + Arr[0];
}

int main(){
    int arr[] = {1,2,3,4};

    int n = sizeof(arr)/sizeof(arr[0]);

    int res = arrSum(arr, n);

    cout<<res<<endl;

    cout<<sumArr(arr, n)<<endl;

    return 0;
}