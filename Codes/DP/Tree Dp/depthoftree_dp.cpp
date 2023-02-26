// Ans[i] -> depth of tree i, if we root tree at i.
// ans[i]=max(indp[i],outdp[i])


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
int n;
vector<int> g[100100];
int indp[100100];
int outdp[100100];

void dfsin(int node,int par){
	// Base case - treat every dp as leaf node here!
	indp[node]=0;

	// Iterate over all childs and update current node
	// according to its child
	for(auto ch:g[node]){
		if(ch!=par){
			dfsin(ch,node);
			indp[node]=max(indp[node],indp[ch]+1);
		}
	}
}

void dfsout(int node, int par,int outval){
	// outval -> outdp of parent
	outdp[node]=outval;

	// Storing first two maxes of all the childs
	int max1=-1,max2=-1;
	for(auto ch:g[node]){
		if(indp[ch]>max1){
			max2=max1;
			max1=indp[ch];
		}else if(indp[ch]>max2){
			max2=indp[ch];
		}
	}

	// iterating over all childs 
	for(auto ch:g[node]){
		if(indp[ch]==max1){
            // outval of child ch -> max(max2+2,outdp[node]+1)
			dfsout(ch,node,max(max2+2,outdp[node]+1));
		}else{
			dfsout(ch,node,max(max1+2,outdp[node]+1));
		}
	}
}
void solve(){
		
}

signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}

