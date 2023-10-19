// Question from InterviewBit: Two teams(Graph and Binary tree)
#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007

vector<int> color(100100); // color[i]=1(team 1) and color[i]=2(team 2)
vector<bool> vis(100100, false);
vector<vector<int>> adj(100100);

bool dfs(int node, vector<vector<int>> &adj, vector<int> &color)
{
    if (color[node] == -1)
    {
        color[node] = 1;
    }

    for (auto nbr : adj[node])
    {
        if (color[nbr] == -1)
        {
            color[nbr] = 1 - color[node];
            if (!dfs(nbr, adj, color))
            {
                return false;
            }
        }
        else if (color[nbr] == color[node])
            return false;
    }
    return true;
}

int main()
{
    int n, m; // n->number of vertices, m->number of edges
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> color(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            if (dfs(i, adj, color) == false)
            {
                return 0;
            }
        }
    }
    cout << "Possible" << endl;

    return 0;
}