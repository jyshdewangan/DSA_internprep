// Given segments of intervals with given value , l r x
// For each query ? y - find largest priority at y

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
	vector<pair<int,ii>> events;
	for(int i=0;i<n;i++){
		int l,r,x;cin>>l>>r>>x;
		events.pb({l,{0,x}}); // Insert event
		events.pb({r,{2,x}}); // Remove event
	}

	// Offline Queries
	int q;cin>>q;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		events.pb({a,{1,i}}); // storing i for answering in respective format
	}

	multiset<int> mt;
	int ans[q];

	for(int i=0;i<events.size();i++){
		if(events[i].s.f==0){
			mt.insert(events[i].s.s);
		}else if(events[i].s.f==2){
			mt.erase(mt.find(events[i].s.s));
		}else{
			if(mt.empty()){
				ans[events[i].s.s]=0;
			}else{
				ans[events[i].s.s]= *mt.rbegin();
			}
		}
	}
	for(int i=0;i<q;i++){
		cout<<ans[i]<<endl;
	}
}

signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}