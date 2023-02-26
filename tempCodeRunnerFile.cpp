// 

// substracting a[i] each time from x, whomsoever gets first negative, loses.

#include <bits/stdc++.h>
using namespace std;

const unsigned int M = 1e9 +7;
#define int long long

	
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	map<string,int> mp;
	for(int i=0;i<n;i++){
		if(s[i]>='A' && s[i]<='Z') mp["s1"]++;
		else if(s[i]>='a' && s[i]<='z') mp["s2"]++;
		else if(s[i]>='0' && s[i]<='9') mp["s3"]++;
		else mp["s4"]++;

	}
		if(mp["s1"]==0) s+='A';
		if(mp["s2"]==0) s+='a';
		if(mp["s3"]==0) s+='0';
		if(mp["s4"]==0) s+='*';

		while(s.length()<7){
			s+='A';
		}
		cout<<"Case #"<<<<": "<<s<<"\n"
;}


signed main(){

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int _t;cin>>_t;while(_t--)
	solve();
}




