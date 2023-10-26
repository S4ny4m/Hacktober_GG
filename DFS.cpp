// This is GOD's workspace.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Graph
{
private:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, bool> visited;
    void DFS(vector<int> &ans, int node)
    {
        stack<int> s;
        s.push(node);
        while (!s.empty())
        {
            int curr = s.top();
            s.pop();
            if (visited[curr])
                continue;
            ans.push_back(curr);
            visited[curr] = 1;
            for (auto i : adj)
            {
                for (auto j : adj[curr])
                    s.push(j);
            }
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

    vector<int> giveDFS(int nodes)
    {
        vector<int> ans;
        for (int i = 1; i < nodes; i++)
        {
            if (!visited[i])
            {
                DFS(ans, i);
            }
        }
        return ans;
    }

    void DFSrecursion(int node, vector<int> &ans)
    {
        if (!visited[node])
        {
            ans.push_back(node);
            visited[node] = true;
            for (auto i : adj[node])
            {
                DFSrecursion(i, ans);
            }
        }
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
    // vector<int> dfsArr = g.giveDFS(nodes);
    vector<int> dfsArr;
    g.DFSrecursion(0, dfsArr);
    cout << "DFS of the Graph :: ";
    for (auto i : dfsArr)
    {
        cout << i << " ";
    }
    return 0;
}