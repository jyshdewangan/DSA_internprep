#include <bits/stdc++.h>
using namespace std;

const unsigned int M = 1e9 +7;
// #define int long long




void solve(){
	int n,m;cin>>n>>m;
	vector<vector<int>> dp(n+2,vector<int>(m+2,0));
	vector<vector<int>> a(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			
				dp[i][j]=max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1]));
				dp[i][j]=max(dp[i][j],a[i][j]);
			
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(dp[i][j]>a[i][j]) cout<<0<<" ";
			else cout<<1<<" ";
		}
		cout<<"\n";
	}

}


signed main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//code here
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}