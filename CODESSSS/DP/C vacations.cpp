// ATCODER C vacations

#include <bits/stdc++.h>
using namespace std;

const unsigned int M = 1e9 +7;
#define int long long


int n,k;
int a[100100][3];
int dp[100100][3];

int rec(int level,int i){
	if(level==0) return max({a[level][0],a[level][1],a[level][2]});

	if(dp[level][i]!=-1) return dp[level][i];

	int ans=0;
	for(int j=0;j<3;j++){
		if(i!=j){
			ans=max(ans,rec(level-1,j)+a[level][j]);
		}
	}
	return dp[level][i]=ans;
}

void solve(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
		}
	}
	memset(dp,-1,sizeof(dp));
	int as=0;
	int apt;
	for(apt=0;apt<3;apt++){
		if(a[n-1][apt]>=as){
			as=a[n-1][apt];
		}
	}
	cout<<rec(n-1,apt)<<"\n";
}


signed main(){

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	// int _t;cin>>_t;while(_t--)
	solve();
}




