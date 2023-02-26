// Number of shortest paths
// Use dist[i][j].S as the No. of shorteest paths till (i,j)

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

using ii = pair<int,int>;
/*
6 6
S.#...
......
####.#
E.##.#
..#..#
#....#
*/

int n,m;	
vector<string> arr;

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

bool inside(int x,int y){
	if(x<0||x>=n||y<0||y>=m||arr[x][y]=='#')return 0;
	else return 1;
}

ii dist[1010][1010];
ii par[1010][1010];

void bfs(ii st){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dist[i][j] = {1e9,0};
		}
	}
	dist[st.F][st.S] = {0,1};
	queue<ii> q;
	q.push(st);
	while(!q.empty()){
		ii cur = q.front();
		q.pop();
		int curd = dist[cur.F][cur.S].F;
		for(int k=0;k<4;k++){
			if(!inside(cur.F+dx[k],cur.S+dy[k]))continue;	

			ii neigh = {cur.F+dx[k],cur.S+dy[k]};
			if(dist[neigh.F][neigh.S].F > curd+1){ // relax
				
				dist[neigh.F][neigh.S] = {curd+1,dist[cur.F][cur.S].S};
				par[neigh.F][neigh.S] = cur;
				q.push(neigh);
			
			}else if(dist[neigh.F][neigh.S].F == curd+1){
				
				dist[neigh.F][neigh.S].S += dist[cur.F][cur.S].S;
			
			}
		}
	}
}

int main(){
	cin>>n>>m;
	arr.resize(n);
	ii st,en;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		for(int j=0;j<m;j++){
			if(arr[i][j]=='S'){
				st = {i,j};
			}else if(arr[i][j]=='E'){
				en = {i,j};
			}
		}
	}
	bfs(st);
	 cout<<dist[en.F][en.S].F<<" "<<dist[en.F][en.S].S<<endl;
}