// FORM 5
// dp[state]-> win or lose {Game theory sort of}
//  Given stack of x, which two players have to fill with given integers in array.
// find if player one wins or loses if he goes first.

// substracting a[i] each time from x, whomsoever gets first negative, loses.


// If there are 0 stones, then the second player wins. 
// If there are x stones in the pile now, the first player can take out A_1, A_2, ... A_n stones. 
// That will make him the second player of (x - A_1), (x - A_2), ... , (x - A_n) stones. 
// If it is known that any of these positions is winning for player 2, then x stones is winning for player 1. 


#include <bits/stdc++.h>
using namespace std;

const unsigned int M = 1e9 +7;
#define int long long

int n,x;
int arr[100100];
int dp[100100];

int rec(int s){ 
	// Prune

	// Base
	if(s==0) return 0;
	// Cache
	if(dp[s]!=-1) return dp[s];
	// Transition
	int ans=0;
	for(int i=0;i<n;i++){
		if(rec(s-arr[i])==0 && arr[i]<=s){
			ans=1;
			break;
		}
	}

	// Save and Return
	return dp[s] =ans;
}
void solve(){
	cin>>n>>x;
	for(int i=0;i<n;i++) cin>>arr[i];
	memset(dp,-1,sizeof(dp));
	cout<<rec(x)<<"\n";



	// FOR DETERMINING PATTERN [HECKKK!!!!]
	// for(int i=0;i<20;i++){
	// 	cout<<i<<" "<<rec(i)<<"\n";
	// }  
}


signed main(){

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	// int _t;	cin>>_t;while(_t--)
	solve();
}




