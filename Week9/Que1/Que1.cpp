#include<iostream>
using namespace std;
#define V 5
#define INF 999999

void printMatrix(int graph[][V]);

void FloyedWarshall(int graph[][V])
{
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            for(int k=0;k<V;k++)
            {
                if(graph[i][j] > graph[i][k]+graph[k][j])
                {
                    graph[i][j] = graph[i][k]+graph[k][j];
                }
            }
        }
    }
    printMatrix(graph);
}

void printMatrix(int graph[][V])
{
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(graph[i][j] == INF)
            {
                cout << "INF ";
            }
            else{
                cout << graph[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int graph[V][V] = {{0,10,5,5,INF},
                       {INF,0,5,5,5},
                       {INF,INF,0,INF,10},
                       {INF,INF,INF,0,20},
                       {INF,INF,INF,5,0}};

    FloyedWarshall(graph);
}
