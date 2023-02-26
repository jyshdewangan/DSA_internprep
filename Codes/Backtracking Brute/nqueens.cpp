// N- Queens

#include <bits/stdc++.h>
using namespace std;

const unsigned int M = 1e9 +7;
#define int long long

int n;
int ans;
vector<int> queens;

bool check(int row,int col){
	for(int prow=0;prow<row;prow++){
		int pcol = queens[prow];
		if(pcol==col || abs(prow-row)==abs(pcol-col)){
			return 0;
		}
	}
	return 1;
}

void rec(int level){ // level = row
    // Debug
    // cout<<level<<"[";
    // for(auto v:queens){
    //     cout<<v<<",";
    // }
    // cout<<"]\n";

	// Base Case
	if(level==n) {
		ans++;
		// for(int i=0;i<n;i++){
		// 	cout<<queens[i]<<" ";
		// }cout<<"\n";
		return;
	}

	// explore for all values
	for(int col=0;col<n;col++){
		// Check the choices
		if(check(level,col)){
		// If fine, make the move
			// set
			queens.push_back(col);
			// level recursion
			rec(level+1);
			// Unset
			queens.pop_back();
		}
	}
}


void solve(){
	cin>>n;
	ans=0;
	rec(0);
	cout<<ans<<"\n";
}


signed main(){

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	// int _t;cin>>_t;while(_t--)
	solve();
}



// **********************************************************************************************
// Different Method
// K knights


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

int check1(int i,int j){
	if(board[i][j]==1) return 0;
	for(int x=0;x<8;x++){
		int nx = i+dx[x];
		int ny = j+dy[x];
		if(nx>=0&&nx<n && ny>=0&&ny<n && board[nx][ny]) return 0;
	}
	return 1;
}

void rec(int level,int knights){ // level- the cell which we have visited (Total n^2 levels)
	if(level==n*n || knights==0){
		if(knights==0){
			ans++;
		}
		return;
	}
	
	int row = level/n;
	int col = level%n;

	// Dont place the knight
	rec(level+1,knights);

	if(knights && check1(row,col)){
		board[row][col]=1;
		rec(level+1,knights-1);
		board[row][col]=0;
	}
}

void solve(){
	cin>>n>>k;
	ans=0;
	rec(0,k);
	cout<<ans<<endl;
}



 
signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}
