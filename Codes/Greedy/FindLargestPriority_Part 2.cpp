// given intervals- l r x ; priority value x from [l,r]
// Queries - ? y z - Find largest x<=z for that particular y.

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

using ii = pair<int,int>;

void solve(){
	int n;
	cin>>n;
	vector<pair<int,ii>> event;
	for(int i=0;i<n;i++){
		int l,r,x;
		cin>>l>>r>>x;
		event.push_back({l,{0,x}});
		event.push_back({r,{2,x}});
	}
	int q;cin>>q;
	ii queries[q];
	for(int i =0;i<q;i++){
		cin>>queries[i].F>>queries[i].S;
		event.push_back({queries[i].F,{1,i}});
	}
	int ans[q];
	sort(event.begin(), event.end());
	multiset<int> mt;
	for(auto v:event){
		if(v.S.F==0){
			mt.insert(v.S.S);
		}else if(v.S.F==1){
			int z = queries[v.S.S].S;
			auto it = mt.upper_bound(z);
			if(it!=mt.begin()){
				it--;
				ans[v.S.S]=*it;
			}else{
				ans[v.S.S]=-1;
			}
		}else{
			mt.erase(mt.find(v.S.S));
		}
	}
	for(int i=0;i<q;i++){
		cout<<ans[i]<<endl;
	}
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}