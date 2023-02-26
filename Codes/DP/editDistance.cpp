#include<bits/stdc++.h> 
using namespace std;
#define im_Fast_asfuck_Nigga ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
#define ii pair<int,int>
#define f first
#define s second
#define MP make_pair
#define pb push_back


long long mod=1e9+7;

int n,m;
int dp[5010][5010];

void solve(){
	string s,t;cin>>s>>t;
	int n=s.length();
	int m=t.length();
	for(int i=0;i<=m;i++){
		dp[0][i]=i;
	}
	for(int i=1;i<=n;i++){
		dp[i][0]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			// dp[i][j]=0;
			if(s[i-1]==t[j-1]){
				dp[i][j]=dp[i-1][j-1];
			}else{
				dp[i][j]=1+min({dp[i][j-1],dp[i-1][j-1],dp[i-1][j]});
			}
		}
	}
	cout<<dp[n][m]<<endl;
}


 
signed main(){		
 
	im_Fast_asfuck_Nigga
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}