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
int dp[3030][3030];
int vis[3030][3030];

int rec(int l,int r){
	if(l>r) return 0;
	if(l==r) return a[l];

	if(vis[l][r]!=-1) return dp[l][r];

	int ans=0;
	ans=max(a[l]-rec(l+1,r),a[r]-rec(l,r-1));
	vis[l][r]=1;
	return dp[l][r]=ans;
}
void solve(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	memset(vis,-1,sizeof(dp));
	
	cout<<rec(0,n-1)<<endl;;

}



 
signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}