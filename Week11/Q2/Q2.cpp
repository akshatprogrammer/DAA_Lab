#include<bits/stdc++.h>
using  namespace std;
int dp[1000][1000];
int count(int idx,int sum,int *arr,int n,vector<vector<int> > &dp){
    
   if(sum==0)
   return 1;

   if(idx>=n || sum<0)
   return 0;

   if(dp[idx][sum]!=-1){
       return dp[idx][sum];
   }
   int left=count(idx,sum-arr[idx],arr,n,dp);
   int right=count(idx+1,sum,arr,n,dp);
   
   dp[idx][sum]=left+right;

   return dp[idx][sum];

        

}

int main(){

    int n;
    cin>>n;

    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int sum;
    cin>>sum;
    vector<vector<int> > dp(n,vector<int>(sum+1,-1));

    cout<<count(0,sum,arr,n,dp)<<endl;



}