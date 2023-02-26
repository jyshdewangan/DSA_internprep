// Find longest subsequence in given array such that difference between consecutive terms is not greater than D
// constraints are to solve in O(nlogn)

#include<bits/stdc++.h> 
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
int n,D,a[100100];

map<int,int> compVal;

// best seen array
int t[400400];

void update(int index,int l,int r, int pos, int val){
	if(pos<l || pos>r) return;
	if(l==r){
		t[index]=max(t[index],val);
		return;
	}
	int mid = (l+r)>>1;
	update(index<<1,l,mid,pos,val);
	update(index<<1|1,mid+1,r,pos,val);
	t[index]=max(t[index<<1],t[index<<1|1]);
}

int query(int index,int l, int r, int lq,int rq){
	if(lq>r || rq<l) return 0;
	if(lq<=l && rq>=r){
		return t[index];
	}

	int mid =(l+r)>>1;
	return max(query(index<<1,l,mid,lq,rq),query(index<<1|1,mid+1,r,lq,rq));
}

void solve(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		compVal[a[i]]++;
	}
	cin>>D;

	// Coordinate compression
	int cnt=0;
	for(auto &v:compVal){
		v.second=cnt++;
	}

	int dp[n];
	int ans=1;
	for(int i=0;i<n;i++){
		int lo = a[i]-D;
		int hi = a[i]+D;

		// Updating hi to actual value present in given array
		auto it = compVal.upper_bound(hi);
		hi--; hi = it->second;

		it = compVal.lower_bound(lo);
		lo= it->second;

		// cnt because we are iterating over compressed coordinate
		// +1 for current element
		dp[i] = query(1,0,cnt-1,lo,hi)+1;
		ans=max(ans,dp[i]);
		// then update the latest value in best seen array
		update(1,0,cnt-1,compVal[a[i]],dp[i]);
	}
	cout<<ans<<endl;
}



 
signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}

// 6 
// 3 5 7 1 2 1
// 2

// 4