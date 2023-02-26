#include<bits/stdc++.h> 
using namespace std;
#define endl '\n'
#define int long long
#define ii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define pb push_back

long long M=1e9+7;


void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> w(n),v(n);
	for(int i=0;i<n;i++){
		cin>>w[i]>>v[i];
	}
	int dp[n+1][m+1];
	for(int i=0;i<=m;i++){
		dp[0][i]=0;
	}
	for(int i=0;i<=n;i++){
		dp[i][0]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(w[i-1]<=j){
				dp[i][j]=max(dp[i-1][j-w[i-1]]+v[i-1],dp[i-1][j]);
			}else dp[i][j]=dp[i-1][j];
		}
	}
	cout<<dp[n][m]<<"\n";
}
 
signed main(){		
 
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	// int _t;	cin>>_t;while(_t--)
	solve();
}