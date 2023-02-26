// Shortest path in given graph

#include<bits/stdc++.h>
using namespace std;



/*
6 6
1 2
2 3
1 4
3 4
4 5
4 6
1
6
*/

int n,m;
vector<vector<int>> g;
int dist[100100];


void bfs(int st){
    for(int i=1;i<=n;i++){
        dist[i] = 1e9;
    }

    dist[st] = 0;
    queue<int> q;
    q.push(st);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        // traverse over neighbors of current node
        for(auto v:g[curr]){
            if(dist[v] > dist[curr]+1){
                dist[v] = dist[curr]+1;
                q.push(v);
            }
        }
    }
}

int main(){
	cin>>n>>m;
    int st,en;
	g.resize(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    cin>>st>>en;
    bfs(st);
    cout<<dist[en]<<"\n";
    // for(int i=1;i<=n;i++){
    //     cout<<dist[i]<<" ";
    // }
}