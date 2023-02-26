// GCD of all nodes in between
// Path Aggregate technique


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
vector<vector<int>> g;
// vector<vector<int>> par;
// vector<int> depth;
int par[1010][1010];
int dp[1010][1010];
int depth[101010];
int val[101010];
int n,m;

void dfs(int node,int prev,int dep){
	par[node][0]=prev;
	depth[node]=dep;
	dp[node][0]=val[node];

	for(int i=1;i<20;i++){
		par[node][i] = par[par[node][i-1]][i-1];
		dp[node][i] = __gcd(dp[node][i-1],dp[par[node][i-1]][i-1]);
	}

	for(auto v:g[node]){
		if(v!=prev){
			dfs(v,node,dep+1);
		}
	}
}

int lca(int u,int v){
	if(depth[u]<depth[v]){
		swap(u,v);
	}

	int ans=0;
	for(int i=19;i>=0;i--){
		if((depth[u]-depth[v])&(1<<i)){
			u = par[u][i];
			ans = __gcd(ans,dp[u][i]);
		}
	}

	if(u==v) return __gcd(ans,val[u]);

	for(int i=19;i>=0;i--){
		if(par[u][i]!=par[v][i]){
			ans=__gcd(ans,dp[u][i]);
			u = par[u][i];
			ans=__gcd(ans,dp[v][i]);
			v=par[v][i];
		}
	}

	// for including numbers at penultimate of lca
	ans= __gcd(ans,val[u]);
	ans= __gcd(ans,val[v]);
	// including lca in gcd
	ans= __gcd(ans,val[par[u][0]]);
	return ans;
}

void solve(){
	cin>>n>>m;
	g.resize(n+1);
	// par.resize(n+1);
	// depth.resize(n+1);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1,-1,0);
	cout<<lca(5,7);
}



 
signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}