// SCRAMBLED STRING
// https://leetcode.com/problems/scramble-string/

#include<bits/stdc++.h> 
using namespace std;
#define im_Fast_asfuck_Nigga ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
#define ii pair<int,int>
#define f first
#define s second
// #define mp make_pair
#define pb push_back

    unordered_map<string,int> mp;
    bool rec(string a, string b){
        if(!a.compare(b)) return true;
        if(a.length()<=1) return false;
        int n= a.length();
        bool flag = false;
        
        string temp=a;
        temp.append(" ");
        temp.append(b);
        
        if(mp.find(temp)!=mp.end()) return mp[temp];
        
        // k loop
        for(int i=1;i<=n-1;i++){
            if((rec(a.substr(0,i),b.substr(n-i,i))&&rec(a.substr(i,n-i),b.substr(0,n-i)))||(rec(a.substr(0,i),b.substr(0,i))&&rec(a.substr(i,n-i),b.substr(i,n-i)))){
                flag=1;
                break;
            }
        }
        return mp[temp]=flag;
    }
void solve(){
	string s1,s2;cin>>s1>>s2;
        if(s1.length()!=s2.length()) {cout<<0;return;}
        if(s1==""&&s2=="") {cout<<1;return;}
        mp.clear();
        cout<<rec(s1,s2)<<endl;
}


 
signed main(){		
 
	im_Fast_asfuck_Nigga
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}