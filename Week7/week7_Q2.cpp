#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void bellmanFord(vector<vector<int> > mat,int v,int s)
{
    int dis[v];
    int parent[v];
    int i,j;
    for(i=0;i<v;i++)
    {
        dis[i]=INT_MAX;
    }

    dis[s]=0;
    parent[s]=s;

    for(int k=0;k<v-1;k++)
    for(i=0;i<v-1;i++)
    {
        for(j=0;j<v;j++)
        {
            if(dis[i]!=INT_MAX && mat[i][j])
            {
                if(dis[j]>dis[i]+mat[i][j])
                {
                    dis[j]=dis[i]+mat[i][j];
                    parent[j]=i;
                }
            }
        }
    }

    for(i=0;i<v;i++)
    {
        if(i==s)
        {
            cout<<i+1<<" : "<<dis[i]<<endl;
            continue;
        }
        cout<<i+1;
        j=i;
        while(parent[j]!=s)
        {
            cout<<" "<<parent[j]+1;
            j=parent[j];
        }
        cout<<" "<<s+1<<" : "<<dis[i]<<endl;
    }
}

int main()
{
    int i,j;

    int v;
    cin>>v;

    vector<vector<int> > mat(v,vector<int> (v));
    for(i=0;i<v;i++)
    for(j=0;j<v;j++)
    cin>>mat[i][j];

    int s;
    cin>>s;

    bellmanFord(mat,v,s-1);

    return 0;
}