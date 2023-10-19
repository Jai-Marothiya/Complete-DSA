// You are given a tree with n nodes numbered from 0 to n - 1 in the form of a parent array parent where parent[i] is the parent of ith node.
// The root of the tree is node 0. Find the kth ancestor of a given node.
// The kth ancestor of a tree node is the kth node in the path from that node to the root node.
// 1<=n<=10^5 and we have given q quaries of K. 1<=q<=10^5
#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<int> a;
vector<vector<int>> query;

signed main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n;
        a.resize(n - 1);
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a[i];
        }
        cin >> q;
        query.resize(q);
        for (int i = 0; i < q; i++)
        {
            int node, k;
            cin >> node >> k;
            query[i].push_back(node);
            query[i].push_back(k);
        }

        vector<vector<int>> par(n, vector<int>(40, -1));
        for (int i = 1; i < n; i++)
        {
            par[i][0] = a[i - 1];
        }
        // par[i][j]: (2^j)th parent of ith node
        for (int j = 1; j < 40; j++)
        {
            for (int i = 1; i < n; i++)
            {
                par[i][j] = par[i][j - 1] < 0 ? -1 : par[par[i][j - 1]][j - 1];
            }
        }

        for (int i = 0; i < q; i++)
        {
            int node = query[i][0], k = query[i][1];

            for (int j = 31; j >= 0; j--)
            {
                if (node < 0)
                    break;
                if (k >> j & 1)
                {
                    node = par[node][j];
                }
            }
            cout << node << endl;
        }
    }

    return 0;
}
