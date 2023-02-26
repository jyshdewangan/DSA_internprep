// H Grid 1
#include<bits/stdc++.h> 
using namespace std;
#define int long long

long long M=1e9+7;

int n,m;
char a[1010][1010];
int dp[1010][1010];

// int rec(int i,int j){
// 	if(i<1 ||j<1 || i>n ||j>m) return 0;
// 	if(i==1 && j==1) return 1;
 
// 	if(dp[i][j]!=-1) return dp[i][j];
 
// 	int ans=0;
// 	if(a[i][j]=='#') ans=0;
// 	else ans=(rec(i-1,j)+rec(i,j-1))%M;
 
// 	return dp[i][j]=ans;
// }


void solve(){
	cin>>n>>m;
	memset(dp,0,sizeof(dp));
	// memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	dp[1][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1 && j==1) continue;
			if(a[i][j]=='#') dp[i][j]=0;
			else{
				dp[i][j]=(dp[i-1][j]+dp[i][j-1])%M;		
			}
		}
	}
	cout<<dp[n][m]%M<<"\n";
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=m;j++){
	// 		cout<<dp[i][j]<<"\t";
	// 	}
	// 	cout<<endl;
	// }
}

signed main(){		

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	// int _t;	cin>>_t;while(_t--)
	solve();
}




