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

int n;
int a[100100];
int t[800400];

void build(int index,int l,int r){
    // Base condition,leaf node
    if(l==r){
        t[index]=a[l];
        return;
    }

    int mid=(l+r)/2;
    // Build left tree
    build(index*2,l,mid);
    // Buildd right tree
    build(index*2+1,mid+1,r);
    // Update the current index value with sum of both child.
    t[index] = t[index*2] + t[index*2+1];
}

void update(int index,int l, int r,int pos,int val){
    // filtering the nodes
    if(pos<l || pos>r) return;
    // updating the leafnode
    if(l==r){
        t[index]=val;
        a[l]=val;
        return;
    }

    // updating all its ancestors 
    int mid=(l+r)/2;
    update(index*2,l,mid,pos,val);
    update(index*2+1,mid+1,r,pos,val);
    t[index] = t[index*2] + t[index*2+1];
    return;
}


int sum(int index,int l,int r,int lq,int rq){
    //  if lq -> rq -> l -> r
    //          OR
    // if  l -> r -> lq -> rq 
    // Then return 0
    if(l>rq || r<lq) return 0;
    if(lq<=l && rq>=r){
        // lq -> l -> r -> rq
        // t[index] stores sum from l to r, not lq to rq
        return t[index];
    }


    // return sum of both sides recursively
    int mid=(l+r)/2;
    return sum(index*2,l,mid,lq,rq) + sum(index*2+1,mid+1,r,lq,rq);
}
void solve(){
    cin>>n;
    int q;cin>>q;
    for(int i=0;i<n;i++)cin>>a[i];

    // Build the segment tree taking root index 1, and from 0-n-1.
    build(1,0,n-1);

 
    for(int i=0;i<q;i++){
        int x;cin>>x;
        if(x==1){
            int pos,val;cin>>pos>>val;
            update(1,0,n-1,pos,val);
        }else{
            int l,r;cin>>l>>r;
            cout<<sum(1,0,n-1,l,r)<<endl;
        }
    }
}


 
signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}