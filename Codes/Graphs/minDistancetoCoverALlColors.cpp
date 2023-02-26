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


struct point{
	int x,y,c;
	// x and y are coordinates of nodes and c is the colour it contain.
};


vector<point> arr;
// (1<<4) -> array representation of 10000 -> this means we havent covered any color yet
// 01111 -> have covered all colors and so on

int dist[10010][(1<<4)];
int vis[10010][(1<<4)];

int manhattdist(point x1,point x2){
	return abs(x1.x-x2.x)-abs(x1.y-x2.y);
}

void dijkstra(){
	// pair<int1,pair<int2,int3>> ->
	// int1 is distance till point int2 which have covered int3 no. of colours.

	priority_queue<pair<int,ii>,vector<pair<int,ii>>,greater<pair<int,ii>>> pq;

	for(int i=0;i<n;i++){
		for(int j=0;j<(1<<4);j++){
			dist[i][j]=1e18;
			vis[i][j]=0;
		}
		// using multi source bfs, pushing all nodes with respective colors in queue.
		dist[i][(1<<arr[i].c)]=0;
		pq.push(mp(0,mp(i,(1<<arr[i].c))));
	}

	while(!pq.empty()){
		auto curr=pq.top();pq.pop();
		int currd = curr.f; // Distance
		int currp = curr.s.f; // point
		int taken = curr.s.s; // the points taken till now

		if(vis[currp][taken]) continue;
		vis[currp][taken]=1;

		for(int i=0;i<n;i++){

			// taken|(1<<arr[i].c) -> addition of current color to previously taken color.
			if(dist[i][taken|(1<<arr[i].c)]>currd+manhattdist(arr[currp],arr[i])){
				dist[i][taken|(1<<arr[i].c)]=currd+manhattdist(arr[currp],arr[i]);
				pq.push(mp(dist[i][taken|(1<<arr[i].c)],mp(i,taken|(1<<arr[i].c))));
			}
		}
	}
}


void solve(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y,c;
		cin>>x>>y>>c;
		arr.pb({x,y,c});
	}
	dijkstra();

	int ans =0;
	for(int i=0;i<n;i++){
		// taking min through all nodes such that all colors are filled atleast once.
		// (1<<4)-1 -> 01111
		ans=min(ans,dist[i][(1<<4)-1]);
	}
	cout<<ans<<endl;
}
 
signed main(){		
 
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	// int _t;	cin>>_t;while(_t--)
	solve();
}