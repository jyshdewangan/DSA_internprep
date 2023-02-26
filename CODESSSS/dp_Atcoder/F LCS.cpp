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
	string s,t;
	cin>>s>>t;
	int n=s.length(),m=t.length();
	int dp[n+1][m+1];

	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0||j==0) {
				dp[i][j]=0;
				continue;
			}
			if(s[i-1]==t[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout<<dp[n][m]<<endl;
	string c="";
	int i=n,j=m;
	while(i>0 && j>0){
		if(s[i-1]==t[j-1]){
			c+=s[i-1];
			j--;
			i--;
		}else{
			if(dp[i-1][j]>dp[i][j-1]){
				i--;
			}else{
				j--;
			}
		}
	}
	reverse(c.begin(),c.end());
	cout<<c<<endl;
}
 
signed main(){		
 
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	// int _t;	cin>>_t;while(_t--)
	solve();
}