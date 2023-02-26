// Find sum of distance of one node to all other nodes
// ans[i]=indp[i]+outdp[i];

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
int ans[100100];
int sz[100100];

int rootval;

void indfs(int node,int par,int h){
	sz[node]=1;
	rootval+=h;
	for(auto v:g[node]){
		if(v==par)continue;
		indfs(v,node,h+1);
		sz[node]+=sz[v];
	}
}

void ansdfs(int node,int par){
	if(node==1){
		ans[node]=rootval;
	}else{
		ans[node]=ans[par]+n-2*sz[node];
	}
	for(auto v:g[node]){
		if(v==par) continue;
		ansdfs(v,node);
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

	indfs(1,0,0);
	ansdfs(1,0);
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<endl;
	}
}

signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}

