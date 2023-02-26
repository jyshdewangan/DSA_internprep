
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
vector<int> generate(vector<int> arr){
	int n = arr.size();
	vector<int> sums;
	for(int i=0;i<(1<<n);i++){
		int sum = 0;
		for(int j=0;j<n;j++){
			if((i>>j)&1){
				sum+=arr[j];
			}
		}
		sums.pb(sum);
	}
	// sums.pb(0); 
	// Sort for Binary search
	sort(sums.begin(),sums.end());
	return sums;
}

int count(vector<int> a,int x){
	int n = a.size();
	vector<int> nums[2];

	// Dividing into two almost equal subparts
	for(int i=0;i<n;i++){
		nums[i%2].pb(a[i]);
	}

	// Two sets
	vector<int> sub0 = generate(nums[0]);
	vector<int> sub1 = generate(nums[1]);


	int ans=0;
	// Iterate on one, Binary search on other
	for(auto v:sub0){
		ans+= upper_bound(sub1.begin(),sub1.end(),x-v)-sub1.begin();
	}

	return ans;

}

void solve(){
	int n,x;cin>>n>>x;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	cout<<count(a,x);
}

signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}