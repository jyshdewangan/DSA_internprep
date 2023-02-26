#include<bits/stdc++.h> 
using namespace std;
#define im_Fast_asfuck_Nigga ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
#define ii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define pb push_back

    int static dp[101][100100];
    int solve(int e,int f){
        if(e==1) return f;
        if(f==0||f==1) return f;
        
        if(dp[e][f]!=-1) return dp[e][f];
        
        int ans=INT_MAX;
        for(int i=1;i<=f;i++){
            
            
            int left,right;
            if(dp[e-1][i-1]!=-1){
                left=dp[e-1][i-1];
            }else {
                left=solve(e-1,i-1);
                dp[e-1][i-1]=left;
            }
            
            if(dp[e][f-i]!=-1){
                right= dp[e][f-i];
            }else{
                right=solve(e,f-i);
                dp[e][f-i]=right;
            }
            
            // int temp = 1 + max(solve(e-1,i-1),solve(e,f-i));
            // Since we need to minimize the number of trials in worst case, we take the maximum of two cases.
            // max due to worst case scenario
            
            int temp = 1+max(left,right);
            ans=min(ans,temp);
        }
        return dp[e][f]=ans;
    }
void solve(){
	int k,n;cin>>k>>n;
        memset(dp,-1,sizeof(dp));
        cout<<solve(k,n)<<endl;
        // cout<<dp[k][n]<<endl;	
}


 
signed main(){		
 
	im_Fast_asfuck_Nigga
	// int _t;	cin>>_t;while(_t--)
	solve();
}