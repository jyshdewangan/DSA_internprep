// 2-FROG
// https://atcoder.jp/contests/dp/tasks/dp_b
#include <bits/stdc++.h>
using namespace std;
 
const unsigned int M = 1e9 +7;
#define int long long
 
int n,k;
int h[100100];
int dp[100100];
 
int rec(int level){
	if(level<=0) return 0;
	if(dp[level]!=-1) return dp[level];
	int ans=1e9;
	for(int i=1;i<=k;i++){
		if(level-i>=0) ans=min({ans,abs(h[level]-h[level-i])+rec(level-i)});
	}
	return dp[level]=ans;
}
 
void solve(){
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>h[i];
	memset(dp,-1,sizeof(dp));
	cout<<rec(n-1)<<"\n";
}
 
 
signed main(){
 
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	// int _t;cin>>_t;while(_t--)
	solve();
}