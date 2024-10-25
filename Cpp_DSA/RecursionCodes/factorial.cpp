#include<iostream>
#include<vector>
using namespace std;

int factorial(int n){
    if(n == 0 || n == 1) return 1;
    return n*factorial(n-1);  
    // time complexity using recursion  = O(2^n)
}


// optimised way of factorial 
int fact(int n){
    std::vector<int>dp(n+1);
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] * i;
    }
    return dp[n];

}
int main(){
     int n{5};
     cout<<factorial(10)<<endl;
     cout<<fact(10)<<endl;
     return 0;
}
