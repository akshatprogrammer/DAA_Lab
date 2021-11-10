#include<bits/stdc++.h>
using namespace std;
int dp[100][100];


int matrixChainMemoized(int *p,int i,int j){
    if(i==j){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    dp[i][j]=INT_MAX;

    for(int k=i;k<j;k++){
        dp[i][j]=min(dp[i][j],matrixChainMemoized(p,i,k)+matrixChainMemoized(p,k+1,j)+p[i-1]*p[k]*p[j]);  
    }
    return dp[i][j];
}
int matrixChainOrder(int *p,int n){
    int i=1,j=n-1;
    return matrixChainMemoized(p,i,j);
}
int main(){
    int arr[]={10,30,5,60};
    int n=sizeof(n)/sizeof(arr[0]);

    memset(dp,-1,sizeof(dp));

    cout<<matrixChainOrder(arr,n)<<endl;





}