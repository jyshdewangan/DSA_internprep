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
struct node{
	int mini;
	int cnt;
	node(int m=1e9,int c=0){
		mini = m;
		cnt =c;
	}
};

node merge(node a, node b){
	if(a.mini==b.mini){
		return node(a.mini,a.cnt+b.cnt);
	}else if(a.mini<b.mini){
		return a;
	}else{
		return b;
	}
}

node t[400100];


void build(int index,int l,int r){
	if(l==r){
		t[index]=node(a[l],1);
		return;
	}

	int mid=(l+r)/2;
	build(index*2,l,mid);
	build(index*2+1,mid+1,r);
	t[index]=merge(t[index*2],t[index*2+1]);
}

void update(int index,int l,int r,int pos,int val){
	if(pos<l || pos>r) return;
	if(l==r){
		t[index]=node(val,1);
		a[l]=val;
		return;
	}

	int mid = (l+r)/2;
	update(index*2,l,mid,pos,val);
	update(index*2+1,mid+1,r,pos,val);
	t[index]=merge(t[index*2],t[index*2+1]);
}

node query(int index,int l,int r,int lq,int rq){
	if(lq>r || rq<l) return 0;
	if(lq<=l && r<=rq){
		return t[index];
	}

	int mid=(l+r)/2;

	return merge(query(index*2,l,mid,lq,rq),query(index*2+1,mid+1,r,lq,rq));
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
			node x = query(1,0,n-1,b,c);
			cout<<x.mini<<" "<<x.cnt<<endl;
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