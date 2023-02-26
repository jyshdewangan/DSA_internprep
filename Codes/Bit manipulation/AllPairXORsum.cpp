// Get all pair XOR sum


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

void solve(){
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];

	int ans=0;
	for(int j=0;j<31;j++){	// for ith bit
		int cnt[2];cnt[0]=cnt[1]=0;
		for(int i=0;i<n;i++){	// iterate over all numbers
			// if(a[i]&(1<<j)){
			// 	cnt[1]++;
			// }else cnt[0]++;
			cnt[(a[i]>>j)&1]++;
		}
		ans+=(cnt[0]*cnt[1])*(1LL<<j);
	}
	cout<<ans<<endl;
}



 
signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}