// This is GOD's workspace.
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Graph
{
private:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

public:
    void addEdge(int u, int v, bool directed)
    {
        // directed==0 ->undirected graph;
        // directed==1 ->directed graph;

        adj[u].push_back(v);
        if (directed == 0)
        {
            adj[v].push_back(u);
        }
    }
    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
                cout << j << ',';
            cout << endl;
        }
    }

    bool isCyclicDFS(int node)
    {
        for (auto j : adj[node])
        {
            if (!visited[j])
            {
                visited[node] = true;
                parent[j] = node;
                bool ans = isCyclicDFS(j);
                if (ans)
                    return ans;
                visited[node] = false;
            }
            else if (visited[j] == 1 && parent[node] != j)
            {
                return 1;
            }
        }
        return 0;
    }

    bool isCyclicBFS(int node)
    {
        queue<int> q;
        parent[node] = -1;
        q.push(node);
        visited[node] = 1;
        while (!q.empty())
        {

            int curr = q.front();
            q.pop();
            for (auto j : adj[curr])
            {
                if (visited[j] == true && j != parent[curr])
                {
                    cout << "Node " << j << " is one of the reason for the cyclic graph.\n";
                    return true;
                }
                else if (visited[j] == 0)
                {
                    q.push(j);
                    visited[j] = true;
                    parent[j] = curr;
                }
            }
        }
        return 0;
    }

    bool checkCyclic(int nodes)
    {
        for (int i = 0; i < nodes; i++)
        {
            if (!visited[i])
            {
                // if (isCyclicBFS(i))
                //     return 1;
                if (isCyclicDFS(i))
                {
                    cout << "present\n\n";
                    return 1;
                }
            }
        }
        return 0;
    }
};
int main()
{
    Graph g;
    int nodes;
    cout << "Enter number of nodes : ";
    cin >> nodes;

    int edges;
    cout << "Enter number of edges : ";
    cin >> edges;

    cout << "Enter nodes: \n";
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 1);
    }

    if (g.checkCyclic(nodes))
        cout << "It is a cyclic graph.\n";
    else
        cout << "It is NOT a cyclic graph.\n";
    return 0;
}