
// 1 x v -> update position x to y
// 2 l r -> find min and count of min from l to r

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


long long mod=1e9+7;
int n,q;
int a[100100];
ii t[400100];

bool comp(ii a,ii b){
	return a.f>b.f;
}
void build(int index,int l,int r){
	if(l==r){
		t[index].f=a[l];
		t[index].s=1;
		return;
	}

	int mid=(l+r)/2;
	build(index*2,l,mid);
	build(index*2+1,mid+1,r);
	if(t[index*2].f==t[index*2+1].f){
		t[index].f=t[index*2].f;
		t[index].s=t[index*2].s+t[index*2+1].s;
	}
	else{
		ii ans = min(t[index*2],t[index*2+1],comp);
		t[index].f=ans.f;
		t[index].s=ans.s;
	}
}

void update(int index,int l,int r,int pos,int val){
	if(pos<l || pos>r) return;
	if(l==r){
		t[index].f= val;
		t[index].s=1;
		a[l]=val;
		return;
	}

	int mid = (l+r)/2;
	update(index*2,l,mid,pos,val);
	update(index*2+1,mid+1,r,pos,val);
	if(t[index*2].f==t[index*2+1].f){
		t[index].f=t[index*2].f;
		t[index].s=t[index*2].s+t[index*2+1].s;
	}
	else{
		ii ans = min(t[index*2],t[index*2+1],comp);
		t[index].f=ans.f;
		t[index].s=ans.s;
	}
}

ii query(int index,int l,int r,int lq,int rq){
	if(lq>r || rq<l) return {0,0};
	if(lq<=l && r<=rq){
		return t[index];
	}

	int mid=(l+r)/2;

	ii ans2;
	t[index*2] = query(index*2,l,mid,lq,rq);
	t[index*2+1] = query(index*2+1,mid+1,r,lq,rq);
	if(t[index*2].f==t[index*2+1].f){
		ans2.f=t[index*2].f;
		ans2.s=t[index*2].s+t[index*2+1].s;
	}
	else{
		ii ans = min(t[index*2],t[index*2+1],comp);
		ans2.f=ans.f;
		ans2.s=ans.s;
	}
	return ans2;
}

void solve(){
	cin>>n>>q;
	for(int i=0;i<n;i++) cin>>a[i];

	build(1,0,n-1);
	for(int i=0;i<q;i++){
		int a,b,c;
		cin>>a;
		if(a==1){
			cin>>b>>c;
			update(1,0,n-1,b,c);
		}
		else{
			cin>>b>>c;
			cout<<query(1,0,n-1,b,c).f<<" "<<query(1,0,n-1,b,c).s<<endl;
		}
	}
}


 
signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}

// 5 2
// 1 2 3 2 2
// 1 2 2
// 2 1 4


// 2 4