// OFFLINE - given an array, find # of elements in range [l,r] which are <=k;
// Query- ? l r k

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
int n,q;
int a[100100];
int t[400400];

void build(int index,int l, int r){
	if(l==r){
		t[index]=0;
		return;
	}
	int mid = (l+r)>>1;
	build(index<<1,l,mid);
	build(index<<1|1,mid+1,r);
}

void update(int index,int l,int r,int pos,int val){
	if(pos<l || pos>r) return;
	if(l==r){
		t[index]=val;
		return;
	}
	int mid =(l+r)>>1;
	update(index<<1,l,mid,pos,val);
	update(index<<1|1,mid+1,r,pos,val);
    t[index] = t[index>>1]+t[index>>1|1];
}

int query(int index,int l,int r,int lq,int rq){
	if(lq>r || rq<l) return 0;
	if(lq<=l && r<=rq){
		return t[index];
	}

	int mid = (l+r)>>1;
	return query(index<<1,l,mid,lq,rq)+query(index<<1|1,mid+1,r,lq,rq);
}

void solve(){
	cin>>n;
	vector<ii> vals;
	for(int i=0;i<n;i++){
		cin>>a[i];
		vals.pb({a[i],i});
	}
	sort(vals.begin(),vals.end());
	cin>>q;
	vector<pair<ii,ii>> queries;
	for(int i=0;i<q;i++){
		int l,r,k;cin>>l>>r>>k;
		queries.pb({{k,i},{l,r}});
	}
	sort(queries.begin(),queries.end());
	build(1,0,n-1);
	int ans[q];
	int pos=0;
	for(auto v:queries){
		while(pos<=vals.size() && vals[pos].f<=v.f.f){
			update(1,0,n-1,vals[pos].s,1);
			pos++;
		}
		ans[v.f.s]=query(1,0,n-1,v.s.f,v.s.s);
	}

	for(auto v:ans){
		cout<<v<<endl;
	}

}



 
signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}