#include<bits/stdc++.h> 
using namespace std;
#define im_Fast_asfuck_Nigga ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
#define ii pair<int,int>
#define f first
#define s second
#define MP make_pair
#define pb push_back


long long mod=1e9+7;
int n,m;
int dist[1010][1010];
int par[1010][1010];




void printpath(int i,int j){
    if(i!=j) printpath(i,par[i][j]);
    cout<<j<<" ";
}

void solve(){
    cin>>n>>m;


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i!=j) dist[i][j]=1e9;
        }
    }

    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        dist[a][b]=1;
    }



    // For printing parent ans min distance (APSP)
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            par[i][j]=i;
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                par[i][j]=par[k][j];
            }
        }
    }

    // Check whether certain node is reachable or not
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dist[i][j] = dist[i][j] | dist[i][k] & dist[k][j];
            }
        }
    }

// for finding shortest cycle , use normal floyd warshal 
// without doing dist[i][i]=1e9 ;
// thus after min of all dist[i][i] will give length of shortest cycle.
// if the min of all these comes out to be negative, it contains negative cycle.

}


 
signed main(){		
 
	im_Fast_asfuck_Nigga
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}