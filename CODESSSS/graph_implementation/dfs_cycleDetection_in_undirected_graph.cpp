#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> visited;
vector<int> parent;
int start = -1, last = -1;
int dfs(int node, int par)
{
    visited[node] = 1;
    parent[node] = par;
    for (auto neigh : g[node])
    {
        if (visited[neigh] && neigh != par)
        {
            start = neigh;
            last = node;
            return 1;
        }
        else if (!visited[neigh])
        {
            int x = dfs(neigh, node);
            if (x)
            {
                return 1;
            }
        }
    }
    return 0;
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    visited.assign(n + 1, 0);
    parent.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            ans = max(dfs(i, 0), ans);
            if (ans)
            {
                break;
            }
        }
    }
    if (ans)
    {
        vector<int> path;
        int temp = last;
        while (temp != start)
        {
            path.push_back(temp);
            temp = parent[temp];
        }
        path.push_back(start);
        path.push_back(last);
        cout << path.size() << "\n";
        for (auto v : path)
            cout << v << " ";
    }
    else
        cout << "IMPOSSIBLE\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int _t;cin>>_t;while(_t--)
    solve();
}
