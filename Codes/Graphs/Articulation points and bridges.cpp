
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
int inTime[100100],loTime[100100];
int timer=0;

void dfs(int node,int par){
	timer++;
	inTime[node]=loTime[node]=timer;
	int child =0;
	bool isArti = false;

	for(auto x:g[node]){
		if(x==par) continue;
		// node-x is forward edge
		if(!inTime[x]){
			child++;
			dfs(x,node);

			// Update only lotime of node
			loTime[node] = min(loTime[node],loTime[x]);

			if(loTime[x]>=inTime[node]){
				isArti=true;
				// node is an articulation point
				// x will be a new component
			}
			else if(loTime[x]>inTime[node]){
				// node-x is a bridge
			}
		}
		else{
			// Backedge
			loTime[node] = min(loTime[node],inTime[x]);
		}
	}

	if((par==0 && child>=2)|| (par!=0 && isArti)){
		// Node is an artuculation point
	}
}


void solve(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    // dfs(1,0); - for articulation points and bridges

}



 
signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}


// ***************************************************************************************************
// How many components will be formed, if we distroy ith node.

int numSplit[100100];

void dfs(int node,int par){
	timer++;
	inTime[node]=loTime[node]=timer;
	int child =0;
	bool isArti = false;

    numSplit[node]=1;

	for(auto x:g[node]){
		if(x==par) continue;
		if(!inTime[x]){
			child++;
			dfs(x,node);

			loTime[node] = min(loTime[node],loTime[x]);

			if(loTime[x]>=inTime[node]){
				isArti=true;
                numSplit[node]++;
			}
			else if(loTime[x]>inTime[node]){
			}
		}
		else{
			loTime[node] = min(loTime[node],inTime[x]);
		}
	}

    if(par==0){
        numSplit[node] = child;
    }	
}

void solve(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    // dfs(1,0); - for articulation points and bridges

    int comp=0;
    for(int i=1;i<=n;i++){
        if(!inTime[i]){
            comp++;
            dfs(i,0);
        }
    }


    for(int i=1;i<=n;i++){
        if(g[i].size()==0){
            cout<<comp-1<<endl;
        }else{
            cout<<comp-1+numSplit[i]<<endl;
        }
    }
}
