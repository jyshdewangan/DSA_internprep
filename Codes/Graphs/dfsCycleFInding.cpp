

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> col;
vector<int> parent;


bool is_cycle = 0;
vector<int> any_cycle;

vector<int> cntcycle; // For finding no. of nodes which are present in any cycle
vector<int> prefixorder;

void dfs(int node,int par){ // O(N+M)
	parent[node] = par; // storing parent node of any given node
	col[node]=2;
	for(auto v:g[node]){
		// add for undirected - it will remove all the single edges which were taken as cycle before
		// if(v==parent[node]) continue;
		if(col[v]==1){ 
			// node - v is a forward edge
			dfs(v,node);
		}else if(col[v]==2){
			// node - v is a back edge
			// We found a cycle !!
			if(is_cycle==0){
				int temp = node;
				while(temp!=v){
					any_cycle.push_back(temp);
					temp=parent[temp];
				}
				any_cycle.push_back(temp); // taking node itself
				reverse(any_cycle.begin(), any_cycle.end());
			}
			cntcycle[node]++; // initialising partial sum
			cntcycle[parent[v]]--; // initialising partial sum
			is_cycle = 1;
		}else if(col[v]==3){
			// node - v is a cross edge
			// unimportant
            // It goes back to node, then hits col[]==3, which describes cross edge.
		}
	}
	col[node]=3;
	prefixorder.push_back(node); // if any node is completed, it is pushed back here

}

int main(){
	int n,m;
	cin>>n>>m;

	g.resize(n+1); // adjacency list/graph
	col.assign(n+1,1); // colour of particular node , may be 0,1 or 2.
	parent.assign(n+1,0);
	cntcycle.assign(n+1,0);

	map<pair<int,int>,int> edgecnt; // For handling multiple edge cycle
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		if(x==y){
			//self-loop
		}
		if(x>y)swap(x,y);
		edgecnt[make_pair(x,y)]++;
		if(edgecnt[make_pair(x,y)]>1){
			//multiple edge cycle
		}else{
			g[x].push_back(y);
			// g[y].push_back(x); - use this when in case of undirected graph
		}
	}
	for(int i=1;i<=n;i++){ // Main dfs loop over graph
		if(col[i]==1){
			dfs(i,0);
		}
	}
	for(auto v:prefixorder){ // prefix sum on graph, only on nodes which are already completed
		cntcycle[parent[v]]+=cntcycle[v]; 
	}
	int cntnode = 0; // For counting distinct nodes among all cycles, whichever node has cntcycle == 0, is not a part of any cycle
	for(int i=1;i<=n;i++){
		if(cntcycle[i]>0)cntnode++;
	}
	cout<<cntnode<<endl;
}