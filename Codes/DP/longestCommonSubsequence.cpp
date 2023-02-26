// FORM 3
// Longest common subsequence/ multisequence form
#include <bits/stdc++.h>
using namespace std;

const unsigned int M = 1e9 +7;
#define int long long

string s1,s2;
int n,m;
vector<vector<int>> dp(2020,vector<int>(2020,-1)); 

int rec(int l1,int l2){ //s1[l1,....|s1[n]|-1]  s2[l2,....|s2[n]|-1]
	// prun

	// base
	if(l1==n || l2==m) return 0;
	// cache
	if(dp[l1][l2]!= -1) return dp[l1][l2];

	// transition
	int ans =0;
	if(s1[l1]==s2[l2]){
		ans = 1+ rec(l1+1,l2+1);
	}else{
		ans=max(rec(l1+1,l2),rec(l1,l2+1));
	}

	// save return
	return dp[l1][l2]=ans;
}


void solve(){
	cin>>s1>>s2;
	n=s1.length();
	m=s2.length();
	// memset(dp,-1,sizeof(dp));
	cout<<rec(0,0);
}


signed main(){

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int _t;	cin>>_t;while(_t--)
	solve();
}