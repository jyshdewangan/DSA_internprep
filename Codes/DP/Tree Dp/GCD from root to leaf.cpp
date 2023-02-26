// # of valif assignments such that all paths from root to leafs has gcd==1
// Tree rooted at 1


#include<bits/stdc++.h> 
#include<experimental/algorithm>
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
int n,m;
vector<int> g[100100];
int dp[100100][20];

int gcd(int a,int b){
	if(a==0||b==0) return a^b;
	else return gcd(a,a%b);
}

int dfs(int node,int gc,int par){
	// cache
	if(dp[node][gc]!=-1) return dp[node][gc];

	int ans=0;
	// iterate over all M values
	for(int col=1;col<=m;col++){
		int temp=1;
		int cntchild=0;
		for(auto ch:g[node]){
			if(ch==par) continue;
			cntchild++;
			temp*=dfs(ch,gcd(gc,col),node);
		}

		// Base case
		if(cntchild==0){
			if(gcd(gc,col)==1){
				ans=ans+1;
			}else{
				ans=ans;
			}
		}else{
			ans+=temp;
		}
	}
	return dp[node][gc]=ans;
}

void solve(){
		
}

signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}

