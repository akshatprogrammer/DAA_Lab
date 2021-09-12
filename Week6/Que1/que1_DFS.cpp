#include<bits/stdc++.h>
using namespace std;
bool checkPath(int node,vector<int>adj[],int s,int d,vector<int>&vis){
	vis[node]=1;
	for(auto it : adj[s]){
		if(it==d)
			return true;

		if(!vis[it]){
			vis[it]=1;
			if(checkPath(it,adj,s,d,vis))
				return true;
		}
	}
	return false;
}
bool isPathDFS(int n,vector<int>adj[],int s,int d){
	if(s==d) return true;
	vector<int>vis(n+1,0);

	for(int i=1;i<=n;i++){
		if(checkPath(i,adj,s,d,vis))
			return true;
	}
	return false;
}
int main(){
	int n;
	int m;
	cin >> n >> m;
	vector<int>adj[n+1];
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int s,d;
	cin >> s >> d;
	if(isPathDFS(n,adj,s,d))
		cout << "True" << endl;
	else
		cout << "False" << endl;


	return 0;
}