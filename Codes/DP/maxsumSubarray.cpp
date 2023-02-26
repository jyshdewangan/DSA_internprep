// DP FORM 2 - SUBSEQUENCE , ENDING AT PARTICULAR VALUE

#include <bits/stdc++.h>
using namespace std;

const unsigned int M = 1e9 +7;
#define int long long

int n;
vector<int> a(100100);
vector<int> dp(100100);
bool saved[100100];
int rec(int level){
	// prun
	if(level<0) return INT_MIN;
	// base
	if(level==0) return a[0];

	// cache
	if(saved[level]) return dp[level];

	// transition
	int ans =0;
	ans= max(a[level],a[level]+rec(level-1));
	saved[level] = 1;

	// save return
	return dp[level] = ans;
}


void solve(){
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		saved[i]=0;
		dp[i]=-1e9;
	}
	int ans =rec(0);
	for(int i=1;i<n;i++){
		ans=max(ans,rec(i));
	}
	cout<<ans<<"\n";
	
}


signed main(){

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int _t;	cin>>_t;while(_t--)
	solve();
}