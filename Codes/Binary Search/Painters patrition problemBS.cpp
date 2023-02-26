// Painters patrition problem, binary search


#include <bits/stdc++.h>
using namespace std;

const unsigned int M = 1e9 +7;
#define int long long

int n,k;
int a[100100];

bool check(int x){
	int lastleft=0;
	int needed=0;
	for(int i=0;i<n;i++){
		if(lastleft>=a[i]){
			lastleft-=a[i];
		}else{
			needed++;
			lastleft=x-a[i];
		}
		if(needed>k) return 0;
	}
	return 1;
}

void solve(){
	cin>>n>>k;
	int lo=0,hi=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		lo=max(lo,a[i]);
		hi+=a[i];
	}
	int ans=0;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		if(check(mid)){
			ans=mid;
			hi=mid-1;
		}else{
			lo=mid+1;
		}
	}
	cout<<ans<<"\n";
}


signed main(){

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int _t;cin>>_t;while(_t--)
	solve();
}




