

#include<iostream>
using namespace std;

int graph[10][10], visited[10], n;

bool cycle(int v,int parent)
{
    visited[v]=1;

    for(int i=0;i<n;i++)
    {
        if(graph[v][i]==1)
        {
            if(!visited[i])
            {
                if(cycle(i,v))
                    return true;
            }
            else if(i!=parent)
                return true;
        }
    }

    return false;
}

int main()
{
    int e,u,v;
    cout<<"Enter vertices and edges: ";
    cin>>n>>e;

    for(int i=0;i<e;i++)
    {
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }

    for(int i=0;i<n;i++)
    {
        if(!visited[i] && cycle(i,-1))
        {
            cout<<"Yes";
            return 0;
        }
    }

    cout<<"No";
    return 0;
}
