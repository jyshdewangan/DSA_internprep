#include<bits/stdc++.h> 
using namespace std;
#define int long long

long long mod=1e9+7;

int n,k;
vector<int> a;
vector<int> prefix;
bool check(int x){
	int zero=0;
	for(int i=0;i<=n-x;i++){
		zero+=x-(prefix[i+x]-prefix[i-1]);
		if(zero>k) return 0;
	}
	return 1;
}
void solve(){
	cin>>n>>k;
	a.assign(n,0);
	prefix.assign(n+1,0);
	prefix[0]=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		
			prefix[i+1]=prefix[i]+a[i];
		
	}
	int lo=1,hi=n,ans =-1;
	while(lo<=hi){
		int mid = lo+(hi-lo)/2;
		if(check(mid)){
			ans =mid;
			// lo=mid+1;
			hi=mid-1;
		}else{
			// ans = mid;
			lo=mid+1;
			// hi = mid-1;
		}
	}
	for(auto v:prefix) cout<<v<<" ";
	// cout<<ans<<"\n";
}

signed main(){		

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int _t;	cin>>_t;while(_t--)
	solve();
}




