// Tree Dp
// Calculating indp and outdp

#include<bits/stdc++.h> 
#include<experimental/algorithm>
using namespace std;

#define FasFasCrow ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
#define ii pair<int,int>
#define f first
#define s second
#define MP make_pair
#define pb push_back


long long M=1e9+7;

int n,m;
vector<int> g[100100];
int indp[100100];
int outdp[100100];
int sz[100100];


void indfs(int node,int par){
	// Base Case
	indp[node]=0;
	sz[node]=1;

	for(auto v:g[node]){
		if(v==par) continue;
		indfs(v,node);

		// Reccurance relations 
		sz[node]+=sz[v];
		indp[node]+=indp[v]+sz[v];
	}
}

void outdfs(int node,int par){
	if(node==1){
		outdp[node]=0;
	}else{
		outdp[node]=outdp[par]+indp[par]-(indp[node]+sz[node])+(n-sz[node]);
	}
	for(auto v:g[node]){
		if(v==par) continue;
		outdfs(v,node);
	}
}
void solve(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}

	indfs(1,0);
	outdfs(1,0);
	for(int i=1;i<=n;i++){
		cout<<indp[i]<<" "<<outdp[i]<<endl;
	}
}

signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}

