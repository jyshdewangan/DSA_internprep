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

void solve(){
	string s;cin>>s;
	int n=s.length();
	// KMP array is one index where, string is 0 index, asusual.
	int kmp[n+1];

	// Remember this 5 lines of code
	int i=0,j=-1;kmp[0]=-1;
	while(i<n){
		while(j!=-1 && s[i]!=s[j]) j=kmp[j];
		j++;i++;
		kmp[i]=j;
	}

	for(int i=0;i<=n;i++){
		cout<<kmp[i]<<" ";
	}
}



 
signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}