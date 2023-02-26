// FORM 4
// L-R DP
//  There are two players , p1 and p2 , who chose optimal score from given 

// array such that (score of p1-score of p2) maximises. one can chose from last or 
// front of array only
// dp[l][r] -> maxScore(p1-p2) in the range [l,r] of given array.


#include <bits/stdc++.h>
using namespace std;

const unsigned int M = 1e9 +7;
#define int long long

int n;
int arr[100100];
int dp[1010][1010];
int saved[1010][1010]; // DP array can be -1. so no memset!
int rec(int l, int r){ 
	// prun
	if(l>r) return 0;
	// base
	if(l==r) return arr[l];
	// Cache
	if(saved[l][r]) return dp[l][r];
	// Transition
	int ans=0;
	ans=max(arr[l]-rec(l+1,r),arr[r]-rec(l,r-1));
	saved[l][r]=1;

	// save return
	return dp[l][r] = ans;
}


void solve(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            saved[i][j]=0;
        }
    }
	cout<<rec(0,n-1)<<"\n";
}


signed main(){

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int _t;	cin>>_t;while(_t--)
	solve();
}


//  TEST CASE
// 1
// 4
// 2 10 5 1

//  3

