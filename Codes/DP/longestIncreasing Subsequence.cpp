
#include <bits/stdc++.h>
using namespace std;

const unsigned int M = 1e9 +7;
#define int long long
int n;
int dp[1010];
vector<int> p(1010);

int lis(int level){
    // prune

    // base
    if(level==0) return 1;
    // cache
    if(dp[level]!=-1) return dp[level];
    // transition
    int ans =0;
    ans= max({ans,lis(level-1)});
    if(p[level]>p[level-1]){
        ans=max(ans,lis(level-1)+1);
    }
    return dp[level] = ans;
    // save and return

}
	
void solve(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>p[i];
    memset(dp,-1,sizeof(dp));
    cout<<lis(n-1)<<"\n";
}


signed main(){

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int _t;cin>>_t;while(_t--)
	solve();
}




