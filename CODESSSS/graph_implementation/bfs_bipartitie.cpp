#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> visited;
vector<int> colored;

int bfs(int node)
{
    queue<int> q;
    q.push(node);
    colored[node] = 1;
    visited[node] = 1;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto neigh : g[front])
        {
            if (!visited[neigh])
            {
                visited[neigh] = 1;
                q.push(neigh);
                colored[neigh] = 1 - colored[front]; 
            }
            else if (visited[neigh] && colored[neigh] == colored[front])
            {
                return false;
            }
        }
    }
    return true;
}

int solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    visited.assign(n + 1, 0);
    colored.assign(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            int ans = bfs(i);
            if (ans == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int _t;cin>>_t;while(_t--)
    if (solve() == 1)
        cout << "YES\n";
    else
        cout << "NO\n";
}