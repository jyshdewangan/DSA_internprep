// https://cses.fi/problemset/task/1194/

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
vector<string> s;
vector<ii> source;
ii person;
ii nikal;
string str="DLUR";

int distm[1010][1010];
int distp[1010][1010];
int par[1010][1010];

int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};

int inside(int i,int j){
	if(i<0 || j<0 || i>n || j>m || s[i][j]=='#') return 0;
	return 1;
}


void bfs(ii st){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			distp[i][j]=1e9;
		}
	}
	queue<ii> q;
	q.push(st);
	distp[st.f][st.s]=0;

	while(!q.empty()){
		ii curr = q.front();q.pop();

		for(int i=0;i<4;i++){
			ii neigh={curr.f+dx[i],curr.s+dy[i]};

			if(!inside(neigh.f,neigh.s)) continue;
			if(distp[neigh.f][neigh.s]>distp[curr.f][curr.s]+1){
				
				distp[neigh.f][neigh.s]=distp[curr.f][curr.s]+1;
				par[neigh.f][neigh.s]=i;
				q.push(neigh);
			
			}
		}

	}
}

void msbfs(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			distm[i][j]=1e9;
		}
	}

	queue<ii> q;
	for(int i=0;i<source.size();i++){
		q.push(source[i]);
		distm[source[i].f][source[i].s]=0;
	}

	while(!q.empty()){
		ii curr = q.front();q.pop();

		for(int i=0;i<4;i++){
			ii neigh={curr.f+dx[i],curr.s+dy[i]};

			if(!inside(neigh.f,neigh.s)) continue;
			if(distm[neigh.f][neigh.s]>distm[curr.f][curr.s]+1){
				distm[neigh.f][neigh.s]=distm[curr.f][curr.s]+1;
				q.push(neigh);
			}
		}

	}
}

void solve(){
	cin>>n>>m;
	s.resize(n+1);
	for(int i=0;i<n;i++){
		cin>>s[i];
		for(int j=0;j<m;j++){
			if(s[i][j]=='M'){
				source.pb({i,j});
				continue;
			}
			if(s[i][j]=='A'){
				person={i,j};
				continue;
			}
		}
	}

	msbfs();
	bfs(person);


	nikal={-1,-1};
	int flag=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0 || j==0 ||i==n-1 || j==m-1){
				if(distm[i][j]>distp[i][j]){
					nikal={i,j};
					flag=1;
					break;
				}
			}
			// if(flag==1) break;
		}
		if(flag==1) break;
	}

	if(nikal.f==-1 && nikal.s==-1){
		cout<<"NO\n";
		return;
	}


	cout<<"YES\n";
	cout<<distp[nikal.f][nikal.s]<<endl;
	vector<int> path;

	while(nikal!=person){
		int p=par[nikal.f][nikal.s];
		path.pb(p);
		nikal={nikal.f-dx[p],nikal.s-dy[p]};
	}
	reverse(path.begin(),path.end());
	for(auto v:path){
		cout<<str[v];
	}
	cout<<endl;
}


 
signed main(){		
 
	im_Fast_asfuck_Nigga
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}