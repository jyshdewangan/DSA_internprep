#include<bits/stdc++.h>
using namespace std;

// N nodes, M edges, Capacity C of fuel.
// Edge -> to,from,fuel cost.
// Node -> P[i] per Litre cost 
// start,end  -> Find minimum cost to go from start to end.
// N<= 10000, C<=100
#define F first
#define S second
#define MP make_pair
using ii = pair<int,int>;

int n,m,C;
vector<ii> g[10010];
int P[10010];

int vis[10001][101];
int dist[10001][101];


int dijk(int st,int en){
	for(int i=1;i<=n;i++){
		for(int j=0;j<=C;j++){
			dist[i][j] = 1e9;
			vis[i][j] = 0;
		}
	}
	priority_queue<pair<int,ii>> pq;
	pq.push(MP(0,MP(st,0)));
	dist[st][0]=0;
	while(!pq.empty()){
		pair<int,ii> cur = pq.top();
		pq.pop();
		int node = cur.S.F;
		int fuel = cur.S.S;
		int dis = -cur.F;
		if(vis[node][fuel])continue;
		vis[node][fuel]=1;
		// Recharge Fuel Transition
		if(fuel<C && dis+P[node]<dist[node][fuel+1]){
			dist[node][fuel+1] = dis+P[node];
			pq.push(MP(-dist[node][fuel+1],MP(node,fuel+1)));
		}
		for(auto v:g[node]){
			if(fuel>=v.S && dist[v.F][fuel-v.S] > dis){
				dist[v.F][fuel-v.S] = dis;
				pq.push(MP(-dist[v.F][fuel-v.S],MP(v.F,fuel-v.S)));
			}
		}
	}
	int mini = 1e9;
	for(int i = 0;i<=C;i++){
		mini = min(mini,dist[en][i]);
	}
	return mini;
}


void solve(){
	
	cin>>n>>m>>C;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=n;i++){
		cin>>P[i];
	}
	int st,en;
	cin>>st>>en;
	cout<<dijk(st,en)<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}