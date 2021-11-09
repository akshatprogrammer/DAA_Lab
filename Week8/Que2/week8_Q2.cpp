
  
#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int wt, src, dest;
    edge(int weight, int source, int destination)
    {
        wt = weight;
        src = source;
        dest = destination;
    }
};

bool cmp(struct edge a, struct edge b)
{
    return a.wt < b.wt;
}

int findParent(int node, vector<int> &parent)
{
    if (node == parent[node])
        return node;
    else
        parent[node] = findParent(parent[node], parent); //   path compression
}

void uni_on(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int main()
{
    int v, e;
    cout << "Enter vertices and edges : ";
    cin >> v >> e;
    vector<edge> arr;
    for (int i = 0; i < e; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;  // weight , source , destination
        arr.push_back(edge(x, y, z));
    }
    sort(arr.begin(), arr.end(), cmp);
    vector<int> parent(v), rank(v);
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
    int cost = 0;
    vector<pair<int, int>> vp;
    for (auto it : arr)
    {
        if (findParent(it.dest, parent) != findParent(it.src, parent))
        {
            cost += it.wt;
            vp.push_back({it.src, it.dest});
            uni_on(it.src, it.dest, parent, rank);
        }
    }
    cout << "Min cost : " << cost;
}