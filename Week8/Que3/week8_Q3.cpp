
  
#include <bits/stdc++.h>
using namespace std;

int get_max(vector<int> &key, vector<bool> &mst)
{
    int maxi = INT_MIN, max_idx;
    for (int i = 0; i < key.size(); i++)
    {
        if (mst[i] == false and key[i] > maxi)
        {
            maxi = key[i];
            max_idx = i;
        }
    }
    return max_idx;
}

void Prims(vector<vector<int>> &g, int v)
{
    vector<int> key(v, INT_MIN);
    vector<bool> mst(v, false);
    vector<int> parent(v, -1);
    key[0] = 0;
    for (int i = 0; i < v - 1; i++)
    {
        int maxi = get_max(key, mst);
        mst[maxi] = true;
        for (int j = 0; j < v; j++)
        {
            if (g[maxi][j] and mst[j] == false and g[maxi][j] > key[j])
            {
                key[j] = g[maxi][j];
                parent[j] = maxi;
            }
        }
    }
    int res = 0;
    for (int i = 1; i < v; i++)
    {
        res += key[i];
    }
    cout << "Maximum Spanning Weight : " << res;
}

int main()
{

    int v, e;
    cout << "Enter vertices and edges : ";
    cin >> v >> e;
    vector<vector<int>> g(v, vector<int>(v, 0));
    for (int i = 0; i < e; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        g[x][y] = wt;
        g[y][x] = wt;
    }
    Prims(g, v);
    return 0;
}