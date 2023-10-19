#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 -> undirected
        // direction = 1 -> directed

        // create an edge from u to v;
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    graph gp;
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        gp.addEdge(u, v, 1);
    }

    // gp.addEdge(1, 2, 0);
    // gp.addEdge(2, 5, 0);
    // gp.addEdge(2, 4, 0);
    // gp.addEdge(4, 5, 0);
    // gp.addEdge(4, 3, 0);
    // gp.addEdge(1, 3, 0);

    gp.printAdjList();

    return 0;
}