// Topological ordering dfs

#include <bits/stdc++.h>
using namespace std;

const unsigned int M = 1e9 +7;
#define int long long

int n,m;
vector<vector<int>> g;
vector<int> vis;
vector<int> topo;


void dfs(int node){
	vis[node] = 1;
	for(auto v:g[node]){
		if(!vis[v]){
			dfs(v);
		}
	}
	topo.push_back(node);
}

signed main(){
	cin>>n>>m;
	g.resize(n+1);
	vis.assign(n+1,0);
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
	}

	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	reverse(topo.begin(),topo.end());
	for(auto v:topo){
		cout<<v<<" ";
	}
}
/*
5 5
1 2
1 3
2 4 
3 4
2 5

1 3 2 5 4
*/