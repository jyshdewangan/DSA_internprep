// https://leetcode.com/problems/cherry-pickup-ii/

#include <bits/stdc++.h>
using namespace std;

const unsigned int M = 1e9 +7;
#define int long long

int n,m;
int a[5050][5050];
int dp[101][101][101][101];

int rec(int r1,int c1,int r2,int c2){
	if(r1>=n || c1>=m || r2>=n || c2>=m || r1<0 ||r2<0 || c1<0 || c2<0) return -1e9;
	if(r1==n-1 && r2==n-1 ) {
		if(c1==c2) return a[r1][c1];
		else return a[r1][c1]+a[r2][c2];
	}

	if(dp[r1][c1][r2][c2]!=-1) return dp[r1][c1][r2][c2];

	int ans=0;
	if(r1==r2 && c1==c2) {
		ans = a[r1][c1];
	}else{
		ans=a[r1][c1]+a[r2][c2];
	}
	ans=ans+max({rec(r1+1,c1-1,r2+1,c2-1),rec(r1+1,c1-1,r2+1,c2),rec(r1+1,c1-1,r2+1,c2+1),
	rec(r1+1,c1,r2+1,c2-1),rec(r1+1,c1,r2+1,c2),rec(r1+1,c1,r2+1,c2+1),
	rec(r1+1,c1+1,r2+1,c2-1),rec(r1+1,c1+1,r2+1,c2),rec(r1+1,c1+1,r2+1,c2+1)});

	return dp[r1][c1][r2][c2]=ans;
}

void solve(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) cin>>a[i][j];
	}
	memset(dp,-1,sizeof(dp));
	cout<<rec(0,0,0,m-1)<<"\n";
}


signed main(){

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int _t;cin>>_t;while(_t--)
	solve();
}




