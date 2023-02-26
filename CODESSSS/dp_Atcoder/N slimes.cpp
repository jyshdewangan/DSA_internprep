#include<bits/stdc++.h> 
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
int a[3030];
int ps[3030];
int dp[3030][3030];
// int vis[3030][3030];

int rec(int l,int r){
	if(l>=r) return 0;


	if(dp[l][r]!=-1) return dp[l][r];
	int ans=1e18;
	for(int k=l;k<r;k++){
		ans=min(ans,rec(l,k)+rec(k+1,r)+a[r]-a[l-1]);
	}
	return dp[l][r]=ans;
}

void solve(){
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++) {cin>>a[i];a[i]=a[i-1]+a[i];}

	rec(0,n);

	cout<<dp[0][n-1];
}



 
signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}