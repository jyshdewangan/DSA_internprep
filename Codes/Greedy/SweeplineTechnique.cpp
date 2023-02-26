// Find intersection and union of given intervals/ sweepline technique
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
	vector<ii> events;
	for(int i=0;i<n;i++){
		int l,r;cin>>l>>r;
		events.pb({l,1});
		events.pb({r,-1});
	}

	sort(events.begin(),events.end());
	int uni=0;
	int inter=0;
	int cnt=0;
	for(int i=0;i<events.size()-1;i++){
		cnt+=events[i].second;
		if(cnt>0){
			// The whole interval will be included in union
			uni+=events[i+1].first - events[i].first;
		}
		if(cnt==n){
			inter+=events[i+1].first - events[i].first;
		}
	}
	cout<<uni<<endl;
	cout<<inter<<endl;
}

signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}