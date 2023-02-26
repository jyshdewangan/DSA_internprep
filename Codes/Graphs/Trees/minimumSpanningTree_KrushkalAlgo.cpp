#include<bits/stdc++.h> 
using namespace std;
#define endl '\n'
#define int long long
#define ii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define pb push_back


struct UnionFind{
	int n, set_size, *parent, *rank;
	UnionFind(){}
	UnionFind(int a){
		n = set_size=a;
		parent = new int[n+1];
		rank = new int[n+1];
		for(int i=1;i<=n;i++){
			parent[i]=i;
			rank[i]=1;
		}
	}

	int find(int x){
		if(parent[x]==x) return x;
		else return parent[x]=find(parent[x]);
	}

	void merge(int x,int y){
		int xroot=find(x),yroot=find(y);
		if(xroot!=yroot){
			if(rank[xroot]>rank[yroot]){
				parent[yroot] = xroot;
				rank[xroot]+=rank[yroot];
			}else{
				parent[xroot]=yroot;
				rank[yroot]+=rank[xroot];
			}
			set_size-=1;
		}
	}

	int size(){
		return set_size;
	}

	void reset(){
		set_size=n;
		for(int i=1;i<=n;i++){
			parent[i]=i;
			rank[i]=1;
		}
	}
	void print(){
		for(int i=1;i<=n;i++){
			cout<<i<<"->"<<parent[i]<<endl;
		}
	}
};
void solve(){
	int n,m;
	cin>>n>>m;

	UnionFind uf(n);

	vector<pair<int,ii>> edgelist;
	
	// edgelist(weight,node1,node2)

	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;

		edgelist.pb(mp(c,mp(a,b)));
	}

	sort(edgelist.begin(),edgelist.end());

	int mst_cost=0;
	int cnt = 0;
	for(auto v:edgelist){
		int x = v.s.f;
		int y = v.s.s;
		if(uf.find(x)!=uf.find(y)){
			cnt++;
			mst_cost+=v.f;
			uf.merge(x,y);
		}
	}

	if(cnt!=n-1){
		cout<<"NO SOLUTION\n";
		return;
	}

	cout<<mst_cost<<endl;
    uf.print();
}
 
signed main(){		
 
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	// int _t;	cin>>_t;while(_t--)
	solve();
}