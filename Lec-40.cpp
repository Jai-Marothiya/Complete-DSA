// Rate in maze problem
#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &m, int n, vector<vector<int>> &visited, int x, int y)
{
    // x, y inside the matrix, m[x][y] == 1 and visited[x][y] == 0
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && m[x][y] == 1 && visited[x][y] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(vector<vector<int>> &m, int n, vector<string> &ans, vector<vector<int>> visited, int x, int y, string &path)
{
    // you have reached x, y

    // base case - if we reached final destination then push the 'path' in ans and then return.
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        // cout << path << endl;
        return;
    }

    // make visited[x][y] = 1, because we cross that position
    visited[x][y] = 1;

    // 4- choices  = D, L, R, U

    // Down
    int newX = x + 1;
    int newY = y;
    if (isSafe(m, n, visited, newX, newY))
    {
        path.push_back('D');
        solve(m, n, ans, visited, newX, newY, path);
        path.pop_back();
    }

    // Left
    newX = x;
    newY = y - 1;
    if (isSafe(m, n, visited, newX, newY))
    {
        path.push_back('L');
        solve(m, n, ans, visited, newX, newY, path);
        path.pop_back();
    }

    // Up
    newX = x - 1;
    newY = y;
    if (isSafe(m, n, visited, newX, newY))
    {
        path.push_back('U');
        solve(m, n, ans, visited, newX, newY, path);
        path.pop_back();
    }

    // Right
    newX = x;
    newY = y + 1;
    if (isSafe(m, n, visited, newX, newY))
    {
        path.push_back('R');
        solve(m, n, ans, visited, newX, newY, path);
        path.pop_back();
    }

    visited[newX][newY] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    // Create a string
    vector<string> ans;

    // if m[0][0] == 0 means, we even not start the maze so return ans right now
    if (m[0][0] == 0)
    {
        return ans;
    }

    // Starting position
    int srcx = 0;
    int srcy = 0;

    // Create visited matrix
    vector<vector<int>> visited = m;

    // initialise with 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }

    string path = "";
    // call recursive function solve
    solve(m, n, ans, visited, srcx, srcy, path);
    // sort our ans vector
    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{
    vector<vector<int>> maze;
    int n;
    cout << "Enter the size of maze : ";
    cin >> n;

    cout << endl
         << "Enter the elements in maze : " << endl;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            temp.push_back(a);
        }
        maze.push_back(temp);
    }

    // call findPath()
    vector<string> ans = findPath(maze, n);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].length(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
