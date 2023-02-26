#include<bits/stdc++.h> 
using namespace std;
#define int long long

long long mod=1e9+7;

void solve(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int lo=0;
    int hi=n-1;
    int ans=-1;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(a[mid]==0){
            lo=mid+1;
        }else{
            ans=mid;
            hi=mid-1;
        }
    }
    cout<<ans<<"\n";
}

signed main(){		

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int _t;	cin>>_t;while(_t--)
	solve();
}