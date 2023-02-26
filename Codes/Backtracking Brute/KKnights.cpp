
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
int n,k;
int ans;
int board[14][14];

int dx[]={2,2,1,-1,-2,-2,-1,1};
int dy[]={-1,1,2,2,1,-1,-2,-2};

int check(int i,int j){
	if(board[i][j]==1) return 0;
	for(int x=0;x<8;x++){
		int nx = i+dx[x];
		int ny = j+dy[x];
		if(nx>=0&&nx<n && ny>=0&&ny<n && board[nx][ny]) return 0;
	}
	return 1;
}

void rec(int level){ // level-No. of knights placed
	// Base Case
	if(level==k){
		ans++;
		return;
	}

	// Explore all cases
	// After placing one knight, we traverse over all boxes in board
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(check(i,j)){
				board[i][j]=1; // Place the knight there
				rec(level+1); // Go into recursion
				board[i][j]=0; // unplace the knight
			}
		}
	}
}

void solve(){
	cin>>n>>k;
	ans=0;
	rec(0);
	for(int i=1;i<=k;i++) ans=ans/i;
	cout<<ans<<endl;
	// Dividing by  k factorial is important, because we count 
	// each configuration k times
    //  - No. of ways to arrange k different knights in an arrangement - k!
    // It is considering all k knights different, since they all are same
}



 
signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}