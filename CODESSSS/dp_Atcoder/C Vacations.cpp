#include<bits/stdc++.h> 
using namespace std;
#define int long long

long long mod=1e9+7;

int n;
int a[100100][3];
int dp[100100][3];


// Recursive
// int rec(int level,int i){
// 	if(level==0) return max({a[level][0],a[level][1],a[level][2]});

// 	if(dp[level][i]!=-1) return dp[level][i];

// 	int ans=0;
// 	for(int j=0;j<3;j++){
// 		if(i!=j){
// 			ans=max(ans,rec(level-1,j)+a[level][j]);
// 		}
// 	}
// 	return dp[level][i]=ans;
// }


// Iterative
void solve(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
		}
	}
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<3;i++){
		dp[0][i]=a[0][i];
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<3;j++){
			int m=0;
			for(int k=0;k<3;k++){
				if(k==j) continue;
				m=max(m,dp[i-1][k]);
			}
			dp[i][j]=a[i][j]+ m;
		}
	}
	int mx=0;
	for(int i=0;i<3;i++){
		mx=max(mx,dp[n-1][i]);
	}
	cout<<mx<<"\n";
}

signed main(){		

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	// int _t;	cin>>_t;while(_t--)
	solve();
}

/*
3
10 40 70
20 50 80
30 60 90

210

DP Array:
 ->upto day i
	0 1 2 3 ... n
0
1
2

dp[i][j]-> max till day i 
*/



