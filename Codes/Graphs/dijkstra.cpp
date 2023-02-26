#include<bits/stdc++.h> 
using namespace std;
#define int long long
#define ii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define pb push_back

long long M=1e9+7;

int n,m,start;
vector<vector<ii>> g(100100);
int dist[100100];
int visited[100100];


void dijkstra(int node){
    for(int i=1;i<=n;i++){
        dist[i]=1e18;
        visited[i]=0;
    }

    priority_queue<ii,vector<ii>,greater<ii>> pq;
    // to keep sorted according to weight which is first in pair
    pq.push(mp(0,node));
    dist[node]=0;

    while(!pq.empty()){


        ii cur=pq.top();pq.pop();
        
            if(visited[cur.s]) continue;
            visited[cur.s]=1;
            // ignoring visited nodes


        for(auto v:g[cur.s]){
            int u=v.s;
            int weight = v.f;
            
            // We cannot put visited check condition here, bc in case of back edge, 
            // it'll not visit that and will not update the previous larger distance


            // If current found distance is less than previous found distance 
            // of any node then update it and push to pq
            if(dist[u]>dist[cur.s]+weight){
                dist[u]=dist[cur.s]+weight;
                pq.push(mp(dist[u],u));
            }
        }
    }

}


void solve(){
	cin>>n>>m>>start;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        g[a].push_back(mp(c,b));
        g[b].push_back(mp(c,a));
    }
    
    dijkstra(start);
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }cout<<endl;
    // for(int i=0;i<=n;i++){
    //     cout<<visited[i]<<" ";
    // }
}

signed main(){		

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	// int _t;	cin>>_t;while(_t--)
	solve();
}

/*
4 4
1 2 1
2 3 2
3 4 3
2 4 7

ans=6 for node 4
*/
