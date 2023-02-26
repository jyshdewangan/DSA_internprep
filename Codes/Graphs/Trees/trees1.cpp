#include<bits/stdc++.h> 
using namespace std;
#define endl '\n'
#define int long long
#define ii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define pb push_back

int n;
vector<int> g[100100];
int par[100100];
int dep[100100];
int subtreesz[100100];
bool isleaf[100100];
int childnum[100100];

void dfs(int node,int parent,int depth){
	dep[node]=depth;
	par[node]=parent;
	childnum[node]=0;
	subtreesz[node]=1;
	for(auto v:g[node]){
		if(v==parent) continue;
		childnum[node]++;
		dfs(v,node,depth+1);
		subtreesz[node]+=subtreesz[v];
	}

	if(childnum[node]==0){
		isleaf[node]=1;
	}
}

void solve(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}

	dfs(1,0,0);
}
 
signed main(){		
 
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	// int _t;	cin>>_t;while(_t--)
	solve();
}