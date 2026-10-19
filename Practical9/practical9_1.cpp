#include <iostream>
#include <queue>
using namespace std;

int graph[10][10], visited[10], n;

void DFS(int v)
{
    cout << v << " ";
    visited[v] = 1;

    for(int i = 0; i < n; i++)
    {
        if(graph[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

void BFS(int start)
{
    int vis[10] = {0};
    queue<int> q;

    q.push(start);
    vis[start] = 1;

    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for(int i = 0; i < n; i++)
        {
            if(graph[v][i] == 1 && vis[i] == 0)
            {
                q.push(i);
                vis[i] = 1;
            }
        }
    }
}

int main()
{
    int e, u, v, start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    for(int i = 0; i < e; i++)
    {
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "DFS: ";
    DFS(start);

    cout << "\nBFS: ";
    BFS(start);

    return 0;
}
