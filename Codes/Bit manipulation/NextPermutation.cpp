
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
int n;
vector<int> a;
map<int,int> mp;
vector<vector<int>> all_sol;
vector<int> cur_sol;

void rec(int level){
	if(level==n){
		all_sol.pb(cur_sol);
		return;
	}

	for(auto v:mp){
		if(v.second!=0){
			cur_sol.pb(v.first);
			mp[v.first]--;
			rec(level+1);
			cur_sol.pop_back();
			mp[v.first]++;
		}
	}
}
void solve(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		a.pb(x);
		mp[x]++;
	}
	rec(0);
	for(auto v:all_sol){
		for(auto x:v){
			cout<<x<<" ";
		}
		cout<<"\n";
	}
}



 
signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}