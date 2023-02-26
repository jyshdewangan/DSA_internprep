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

// GCD code!!!!
int gcd(int a, int b){
	if(a==0 || b==0) return a+b;
	return gcd(a,a%b);
}

// Getting reduced fraction
ii get_red_frac(int a,int b){
	if(a==0&&b==0) return MP(0,0);
	if(a==0) return MP(0,1);
	if(b==0) return MP(1,0);

	int x = gcd(a,b);
	return MP(a/x,b/x);
}

void solve(){
	int n;cin>>n;
	int a[n];
	map<ii,int> mp;
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];

		// Implementation of ans
		// [3,1,3,3]
		// 0+1+2=3=3C2 (3 Chose 2)

		ans+=mp[get_red_frac(a[i],i)];
		mp[get_red_frac(a[i],i)]++;
	}
	cout<<ans<<endl;
}

signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}





// *************************************************************************************************************

// Q. Given points in 2d cartesian system, find max no. of points present in a line

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

// GCD code!!!!
int gcd(int a, int b){
	if(a==0 || b==0) return a+b;
	return gcd(b,a%b);
}

// Getting reduced fraction
ii get_red_frac(int a,int b){
	if(a==0&&b==0) return MP(0,0);
	if(a==0) return MP(0,1);
	if(b==0) return MP(1,0);


	// a,b can be negative
	int neg=1;
	if(a<0){neg*=-1;a*=-1;}
	if(b<0){neg*=-1;b*=-1;}
	int x = gcd(a,b);
	return MP(neg*a/x,b/x);
}

void solve(){
	int n;cin>>n;
	int x[n],y[n];
	int ans=0;
	for(int i=0;i<n;i++) cin>>x[i]>>y[i];
	for(int i=0;i<n;i++){
		map<ii,int> mp;
		int same=0;
		for(int j=0;j<n;j++){
			if(x[i]!=x[j] || y[i]!=y[j]){
				// Storing the slopes in map
				mp[get_red_frac(y[j]-y[i],x[j]-x[i])]++;
			}
			else{
				// if the input points are same, otherwise it 
				// was considering (0,0) slope to be same as (1,1) slope
				same++;
			}
		}
		for(auto v:mp){
			ans=max(ans,same+v.s);
		}
	}
	cout<<ans<<endl;
}

signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}