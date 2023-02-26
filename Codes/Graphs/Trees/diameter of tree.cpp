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

void dfs(int node,int parent,int depth){
	par[node]=parent;
	dep[node]=depth;
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
	int mini=1;
	for(int i=2;i<=n;i++){
		if(dep[mini]<dep[i]){
			mini = i;
		}
	}
	dfs(mini,0,0);
	int minim=mini;
	for(int i=1;i<=n;i++){
		if(dep[minim]<dep[i]){
			minim = i;
		}
	}
	cout<<"Diameter of tree is: "<<dep[minim]<<endl;



	// For finding center of trees
    // if (d & 1)
    // {
    //     cout<<-1;
    // }
    // else
    // {
    //     int c;
    //     int i = d / 2;
    //     int temp = p2;
    //     while (i--)
    //     {
    //         temp = parent[temp];
    //     }
    //     c = temp;
    //     cout<<temp;
    // }
}
 
signed main(){		
 
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	// int _t;	cin>>_t;while(_t--)
	solve();
}