// 3 types of queries:
// 1 l r -> find sum of elements [l,r]
// 2 l r -> find max in [l,r]
// 3 l r v -> update a[i]=v in i in range [l,r]

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


struct node{
	int sum,maxi,lazy;
	node(){
		sum=0;
		maxi=0;
		lazy=0;
	}
};

node t[400400];

node merge(node a,node b){
	node temp;
	temp.sum = a.sum + b.sum;
	temp.maxi = max(a.maxi,b.maxi);
	return temp;
}

void push(int index,int l,int r){
	// only when the node is marked lazy
	if(t[index].lazy){
		// passing the value via t[index].lazy
		t[index].sum = t[index].lazy*(r-l+1);
		t[index].maxi = t[index].lazy;
		// If the given node is not leaf node, mark its both childs as lazy
		if(l!=r){
			t[index<<1].lazy=t[index].lazy;
			t[index<<1|1].lazy=t[index].lazy;
		}
		// Unmark this node as lazy
		t[index].lazy=0;
	}
}


void update(int index,int l, int r,int lq,int rq,int val){
	// Updating values
	push(index,l,r);

	if(lq>r || rq<l) return;

	if(lq<=l && r<=rq){
		// marking the node as lazy
		t[index].lazy = val;
		// pushing it so that it will give correct values to its ancestors
		push(index,l,r);
		return;
	}

	int mid=(l+r)>>1;
	update(index<<1,l,mid,lq,rq,val);
	update(index<<1|1,mid+1,r,lq,rq,val);
	t[index]=merge(t[index<<1],t[index<<1|1]);
}

node query(int index,int l,int r,int lq,int rq){
	// Update the node first before querrying
	push(index,l,r);

	if(lq>r || rq<l) return node();
	if(lq<=l && r<=rq){
		return t[index];
	}

	int mid =(l+r)>>1;

	return merge(query(index<<1,l,mid,lq,rq),query(index<<1|1,mid+1,r,lq,rq));
}


void solve(){
	// No need of build in such, as all values are initialised as 0
	// 3 0 5 3
	update(1,0,9,0,5,3);
	// 3 6 9 4
	update(1,0,9,6,9,4);
	// 1 3 6
	// 2 3 6
	node x = query(1,0,9,3,6);
	cout<<x.sum<<" "<<x.maxi<<endl;
}



 
signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}
