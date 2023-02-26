
// Q. find the number of subarrays having distinct elements <=k.

#include <bits/stdc++.h>
using namespace std;

const unsigned int M = 1e9 +7;
#define int long long




void solve(){
    int n,k;
	cin>>n>>k;
    int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
    // DS for two pointers
    int cntzero=0;
    int ans=0;
    // Pointers
    int head=-1,tail=0;
    while(tail<n){
        // While there is a next element to take and we will not voilate any condition
        // (a[head+1]==0)+cntzero<=k
        while(head+1<n && ((a[head+1]==1 && cntzero<=k)|| (a[head+1]==0) && cntzero<k )){
            head++;
            if(a[head]==0) cntzero++;
        }
        // Debug
        // cout<<tail<<" "<<head<<"\n";
        // Update the answer accordingly
        ans= max(ans,head-tail+1);
        // move tail ahead and remove the last element's contribution
        if(head>=tail){
            if(a[tail]==0) cntzero--;
            tail++;
        }else{
            tail++;
            head=tail-1;
        }
    }
    cout<<ans<<"\n";
}


signed main(){

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int _t;cin>>_t;while(_t--)
	solve();
}




