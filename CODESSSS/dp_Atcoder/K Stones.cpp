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


long long mod=1e9+7;
int n,k;
int a[100100];
int dp[100100];

int rec(int k){
	if(k==0) return 0;

	if(dp[k]!=-1) return dp[k];
	int ans=0;
	for(int i=0;i<n;i++){
		if(a[i]<=k && rec(k-a[i])==0){
			ans++;
			break;
		}
	}
	return dp[k]=ans;
}
void solve(){
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	memset(dp,-1,sizeof(dp));
	
	rec(k);
	if(dp[k]) cout<<"First\n";
	else cout<<"Second\n";
}



 
signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}