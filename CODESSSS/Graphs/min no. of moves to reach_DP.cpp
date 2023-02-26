


#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define MP make_pair

int n,m;
vector<string> arr;

int dx[] = {0,1,0,-1}; 
int dy[] = {1,0,-1,0};

using state = pair<int,int>;

int dist[1010][1010];

bool check(int x,int y){
	if(x<0||x>=n||y<0||y>=m||arr[x][y]=='#')return 0;
	return 1;
}

pair<int,int> dp[1010][1010][4];

// this rec gives the last cell ill reach if i follow same direction.
pair<int,int> rec(int i,int j,int dir){
	if(dp[i][j][dir]!=MP(-1,-1))return dp[i][j][dir];
	int x = i+dx[dir];
	int y = j+dx[dir];
	if(check(x,y)){
		return dp[i][j][dir] = MP(i,j);
	}else{
		return dp[i][j][dir] = rec(x,y,dir);
	}
}

void bfs(state st){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dist[i][j] = 1e9;
		}
	}
	dist[st.F][st.S] = 0;
	queue<state> q;
	q.push(st);
	while(!q.empty()){
		state cur = q.front(); q.pop();
		int dcur = dist[cur.F][cur.S];
		for(int k=0;k<4;k++){
			state v = rec(cur.F,cur.S,k);
			if(check(v.F,v.S)&&dist[v.F][v.S]>dcur+1){
				dist[v.F][v.S]=dcur+1;
				q.push(v);
			}
		}
	}
}
void solve(){
	cin>>n>>m;
	arr.resize(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){	
			dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=dp[i][j][3]= MP(-1,-1);
		}
	}
	state st;
	cin>>st.F>>st.S;
	bfs(st);

	state en;
	cin>>en.F>>en.S;
	cout<<dist[en.F][en.S]<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}


// 2nd way of solving same problem , 0-1 BFS



#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define MP make_pair
int n,m;
vector<string> arr;

int dx[] = {0,1,0,-1}; 
int dy[] = {1,0,-1,0};

using state = pair<pair<int,int>,int>;

int dist[1010][1010][4];

bool check(int x,int y){
	if(x<0||x>=n||y<0||y>=m||arr[x][y]=='#')return 0;
	return 1;
}
void bfs(state st){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dist[i][j][0] =dist[i][j][1] =dist[i][j][2] =dist[i][j][3] = 1e9;
		}
	}
    // deque due to 0-1 bfs
	deque<state> q;
    // pushing all directions in deque
	for(int k=0;k<4;k++){
		dist[st.F][st.S][k] = 1;
		q.push(MP(MP(st.F,st.S),k));
	}

	while(!q.empty()){
		state cur = q.front(); q.pop();
		int dcur = dist[cur.F.F][cur.F.S][cur.S];
		// same direction
		int x = cur.F.F + dx[cur.S];
		int y = cur.F.S + dx[cur.S];
		if(check(x,y)){
			if(dist[x][y][cur.S] > dcur){
				dist[x][y][cur.S] = dcur;
				dq.push_front(MP(MP(x,y),cur.S));
			}else{
				// no change
			}
		}else{
            // changing direction, cost us, thus push_back
			for(int k=0;k<4;k++){
				state v = MP(cur.F,k);
				if(check(v.F.F,v.F.S)&&dist[v.F.F][v.F.S][k]>dcur+1){
					dist[v.F.F][v.F.S][k]=dcur+1;
					q.push_back(v);
				}
			}
		}
	}
}
void solve(){
	cin>>n>>m;
	arr.resize(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){	
			dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=dp[i][j][3]= MP(-1,-1);
		}
	}
	state st;
	cin>>st.F>>st.S;
	bfs(st);
	state en;
	cin>>en.F>>en.S;
	cout<<dist[en.F][en.S]<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}