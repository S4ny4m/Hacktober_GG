// This is GOD's workspace.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Graph
{
private:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, bool> visited;
    void BFS(vector<int> &ans, int node)
    {
        queue<int> q;
        q.push(node);
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            if (visited[curr])
                continue;
            ans.push_back(curr);
            visited[curr] = 1;

            for (auto j : adj[curr])
                q.push(j);
        }
    }

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

    vector<int> giveBFS(int nodes)
    {
        vector<int> ans;
        for (int i = 1; i < nodes; i++)
        {
            if (!visited[i])
            {
                BFS(ans, i);
            }
        }
        return ans;
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
        g.addEdge(u, v, 0);
    }
    g.printAdjList();
    vector<int> bfsArr = g.giveBFS(nodes);
    cout << "BFS of the Graph :: ";
    for (auto i : bfsArr)
    {
        cout << i << " ";
    }
    return 0;
}