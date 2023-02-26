// bitwise operations AZ


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
	int cnt[21];
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=0;j<=20;j++){
			if(a[i]&(1<<j)){
				cnt[j]++;
			}
		}
	}

	int ans =0;
	for(int i=0;i<n;i++){
		int largepos=0;
		for(int j=0;j<=20;j++){
			if(cnt[j]){
				largepos|=(1<<j);
				cnt[j]--;
			}
		}
		ans = largepos*largepos;
	}
	cout<<ans<<endl;
}



 
signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}