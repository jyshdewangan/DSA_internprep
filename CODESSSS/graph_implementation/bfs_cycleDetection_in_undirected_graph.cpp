#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> visited;
vector<int> parent;
int bfs(int node,int par){
    queue<int>q;
    q.push(node);
    parent[node]=par;
    visited[node]=1;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto neigh:g[front]){
            if (!visited[neigh]){
                visited[neigh]=1;
                q.push(neigh);
                parent[neigh]=front;
            }else if(visited[neigh] && neigh!=parent[front]){
                return 1;
            }
        }
    }return 0;
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
            ans =bfs(i, 0);
            if (ans==1)
            {
                break;
            }
        }
    }
    if (ans==1)
        cout << "YES\n";
    else
        cout << "NO\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int _t;cin>>_t;while(_t--)
    solve();
}