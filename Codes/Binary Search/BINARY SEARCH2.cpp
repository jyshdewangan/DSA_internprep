#include<bits/stdc++.h> 
using namespace std;
#define int long long

long long mod=1e9+7;
int n,X;
int a[100100];

int check(int x){
    if(a[x]>X) return 1;
    return 0;
}


// FOR ROTATED ARRAY FUNCTION
// int check(int x){
//     if(a[0]>a[x]) return 1;
//     return 0;
// } 
// n-ans will be final answer and initialise ans with n


void solve(){
    cin>>n;
    cin>>X;
    for(int i=0;i<n;i++) cin>>a[i];
    int lo=0;
    int hi=n-1;
    int ans=0;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(check(mid)){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
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