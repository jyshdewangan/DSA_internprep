#include<bits/stdc++.h> 
using namespace std;
#define endl '\n'
#define int long long
#define ii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define pb push_back

int n,dia,c1,c2;
vector<int> g[100100];
int par[100100];
int dep[100100];
int cnt;
vector<int> arr;

void dfs(int node,int parent,int depth){
	par[node]=parent;
	dep[node]=depth;
	if(dep[node]==(dia)/2) cnt++;
	for(auto v:g[node]){
		if(v==parent) continue;
		dfs(v,node,depth+1);
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
	int pt1 =1;
	for(int i=1;i<=n;i++){
		if(dep[pt1]<dep[i]){
			pt1=i;
		}
	}
	dfs(pt1,0,0);
	int pt2=pt1;
	for(int i=1;i<=n;i++){
		if(dep[pt2]<dep[i]){
			pt2=i;
		}
	}
	dia=dep[pt2];
	// cout<<dep[pt2]<<endl;
	if(dia%2==0){
		c1=pt2;
		for(int i=0;i<dia/2;i++){
			c1=par[c1];
		}

		int ans=0;
		for(auto v:g[c1]){
			int c2=v;
			cnt=0;
			dfs(c1,c2,0);
			int ab=cnt;
			cnt=0;
			dia=dia-1;
			dfs(c2,c1,0);
			int bc=cnt;
			dia=dia+1;
			ans+=ab*bc;
		}
		cout<<ans/2<<endl;

	}else{
		c1=pt2;
		for(int i=0;i<dia/2;i++){
			c1=par[c1];
		}
		c2=par[c1];
		// cout<<c1<<" "<<c2<<endl;	
		cnt=0;
		dfs(c1,c2,0);
		int ab=cnt;
		cnt=0;
		dfs(c2,c1,0);
		int bc=cnt;
		cout<<ab*bc<<endl;	
	}

}
 
signed main(){		
 
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	// int _t;	cin>>_t;while(_t--)
	solve();
}

/*
5
1 3
1 2
3 4
3 5

2

11
1 2
1 3
3 4
3 5
4 8
4 6
4 7
3 9
9 10
9 11

11



15
1 2 
2 10
2 9
2 8
10 11
1 5
5 4
5 6
6 7
1 3
1 12
12 13
12 14
14 15


3


*/