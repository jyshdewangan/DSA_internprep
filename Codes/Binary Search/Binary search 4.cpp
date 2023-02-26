
//  minimise the maximum neighbouring distance, k points is to be inserted in array of n elements.

#include <bits/stdc++.h>
using namespace std;

const unsigned int M = 1e9 +7;
#define int long long

int n,k;
int a[100100];

bool check(int x){
	int points=0;
	for(int i=0;i<n-1;i++){
		points+= (((a[i+1]-a[i])+x-1)/x)-1;
		if(points>k) return 0;
	}
	return 1;
	// return points<=k;
}

void solve(){
	cin>>n>>k;
	int lo=0,hi=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++) hi=max(hi,a[i]-a[i-1]);
	int ans=-1; // Default
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




