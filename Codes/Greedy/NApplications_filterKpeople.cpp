// total N applications, filter k people such that
// sum(efficiency of all k people)*min(speed of all k people) is maximised

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

struct ppl{
	int eff,speed;
};

bool comp(ppl a, ppl b){
	return a.speed>b.speed;
}

void solve(){
	int n,k;cin>>n>>k;
	vector<ppl> a;
	for(int i=0;i<n;i++){
		int x,y;cin>>x>>y;
		a.pb({x,y});
	}
	sort(a.begin(),a.end(),comp);

	int ans=0;
	priority_queue<int> pq;
	for(int i=0;i<n;i++){
		if(i>=k-1){
			int sum=0;
			queue<int> q;
			for(int j=1;j<=k-1;j++){
				int aa=pq.top();pq.pop();
				sum+=aa;
				q.push(aa);
			}
			while(!q.empty()){
				int aa=q.front();
				pq.push(aa);
				q.pop();
			}
			ans=max(ans,a[i].speed*(a[i].eff+sum));
		}
		pq.push(a[i].eff);	
	}
	cout<<ans<<endl;
}

signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}