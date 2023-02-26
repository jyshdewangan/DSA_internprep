// Topological ordering bfs

#include <bits/stdc++.h>
using namespace std;

const unsigned int M = 1e9 +7;
#define int long long

int n,m;
vector<vector<int>> g;
vector<int> vis;
vector<int> topo;
vector<int> indeg;
// vector<int> outdeg;

void kahn(){
    queue<int> q;
    // priority_queue<int,vector<int>,greater<int>> q; // For lexicographically topological order
    for(int i=1;i<=n;i++){
        if(indeg[i]==0) q.push(i);
    }

    while(!q.empty()){
        int curr = q.front();
        // int curr = q.top(); // For lexicographically topological order
        q.pop();
        topo.push_back(curr);
        for(auto v:g[curr]){
            indeg[v]--;
            if(indeg[v]==0){
                q.push(v);
            }
        }
    }
}

signed main(){
	cin>>n>>m;
	g.resize(n+1);
	vis.assign(n+1,0);
	indeg.assign(n+1,0);
	// outdeg.assign(n+1,0);
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
        indeg[y]++;
        // outdeg[x]++;
    }

    kahn();


    // If there's a cycle, topo vector will not be completed. 
    // Detecting cycle or not in directed graphs.
    if(topo.size()!=n){
        cout<<"There's a cycle!\n";
    }else{
    	for(auto v:topo){
		    cout<<v<<" ";
	    }    
    }


}
/*
5 5
1 2
1 3
2 4 
3 4
2 5

1 2 3 5 4

if Lexicographically topological order:
1 2 3 4 5
*/