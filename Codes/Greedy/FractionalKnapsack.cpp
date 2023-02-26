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

struct container{
	int limit,price;
};

bool comp(container a, container b){
	return 1ll*a.price*b.limit < 1ll*a.limit*b.price;
}

void solve(){
	int n;cin>>n;
	vector<container> a;
	for(int i=0;i<n;i++){
		int x,y;cin>>x>>y;
		a.pb({x,y});
	}

	sort(a.begin(),a.end(),comp);

	int w;cin>>w;

	long double mincost=0;
	for(int i=0;i<n;i++){
		int totake = min(w,a[i].limit);
		w-=totake;
		mincost+= (totake*1LL*a[i].limit)/(long double)a[i].price;
	}
	cout<<mincost<<endl;
}

signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}