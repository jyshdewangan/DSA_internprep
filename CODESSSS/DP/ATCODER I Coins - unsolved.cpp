// ATCODER I Coins - unsolved

#include <bits/stdc++.h>
using namespace std;

const unsigned int M = 1e9 +7;
#define int long long
// #define dobb double


int n,k;
long double a[100100];
long double dp[5050][5050];

long double rec(int level,int need){
	// if(need==0) 
	if(level==n){
		if(need==0) return 1;
		// else return 1-a[n-1];
		else return 0;
	}

	if(dp[level][need]!=-1) return dp[level][need];

	long double ans=0;
	ans= (rec(level+1,need)*(1-a[level]))+(rec(level+1,need-1)*a[level]);
	return dp[level][need]=ans;
}

void solve(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	memset(dp,-1,sizeof(dp));
	
	long double tot=0;
	for(int i=(n/2)+1;i<=n;i++){
		tot+=rec(0,i);
	}
	cout<< fixed << setprecision(10)<<tot<<"\n";
}


signed main(){

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	// int _t;cin>>_t;while(_t--)
	solve();
}




