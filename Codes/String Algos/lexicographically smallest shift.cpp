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

int quickhash(string s,int p,int mod){
	int ans = s[0]-'a'+1;
	for(int i=1;i<s.length();i++){
		ans = (ans*p + (s[i]-'a'+1))%M;
	}
	return ans;
}
struct hasher{
	int sz,mod,p;
	vector<int> fhash;
	vector<int> pk; // for getting hash, exponents of p

	void init(string s, int _p,int _mod){
		mod=_mod;
		p=_p;
		sz=s.length();
		fhash.resize(sz);
		pk.resize(sz);
		fhash[0] = (s[0]-'a'+1);
		pk[0]=1;
		for(int i=1;i<sz;i++){
			fhash[i]= (fhash[i-1]*p + (s[i]-'a'+1))%mod;
			pk[i] = (pk[i-1]*p)%mod;
		}
	}

	int gethash(int l,int r){
		if(l==0) return fhash[r];
		else return ((fhash[r]-fhash[l-1]*pk[r-l+1])%mod+mod)%mod;
	}
};

int n;
string s;
hasher shash;

bool cmp(int i,int j){
	int lo=1;
	int hi=n;
	int ans=0;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		if(shash.gethash(i,i+mid-1)==shash.gethash(j,j+mid-1)){
			ans=mid;
			lo=mid+1;
		}else{
			hi=mid-1;
		}
	}
	if(ans==n){
		return 0;
	}else return s[i+ans]<s[j+ans];
}

void solve(){
	cin>>s;
	n=s.length();
	s=s+s;
	shash.init(s,37,1e9+7);
	vector<int> final;
	for(int i=0;i<n;i++) final.pb(i);

	sort(final.begin(),final.end(),cmp);
	for(auto v:final){
		cout<<v<<" ";
	}
}


// abaac

// 2 0 3 1 4
 
signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}