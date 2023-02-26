// Find lexicographically largest subsequence in the given string


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
	string s;
	cin>>s;
	string ans;
	for(auto ch:s){
		while(!ans.empty() && ans.back()<ch){
			ans.pop_back();
		}
		ans.push_back(ch);
	}
	cout<<ans;
}

signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}