
#include <bits/stdc++.h>
using namespace std;

const unsigned int M = 1e9 +7;
#define int long long



void solve(){
	int n,m;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	cin>>m;
	int sum =0;
	for(int i=0;i<m;i++) {
		int k;cin>>k;
		sum+=k;
	}
    sum=sum%n;
	// rot(a,sum%n);
	cout<<a[sum]<<"\n";
}


signed main(){

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int _t;cin>>_t;while(_t--)
	solve();
}




