
// MATH BASICS


#include <bits/stdc++.h>
using namespace std;

const unsigned int M = 1e9 +7;
#define int long long

// If no. is prime or not
bool isPrime(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return 0;
    }
    return 1;
}

// Find all divisors
vector<int> allDivisors(int x){
    vector<int> v;
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            v.push_back(i);
            if(i*i!=x) v.push_back(x/i);
        }
    }
    return v;
}

// Find factors of x
vector<pair<int,int>> factors(int x){
    vector<pair<int,int>> ans;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            int cnt=0;
            while(x%i==0){
                cnt++;
                x=x/i;
            }
            ans.push_back({i,cnt});
        }
    }
    if(x>1){
        ans.push_back({x,1});
    }
    return ans;
 }

// Factorising in O(logN)

// Using SP Array [Pre-Computation]
int n, sp[n];

int factor(){
    for(int i=2;i<=n;i++) sp[i]=i;
    for(int i=2;i<=n;i++){
        if(sp[i]==i){ // That means it is a prime
            for(int j=2*i;j<=n;j+=i){
                if(sp[j]==j) sp[j]=i; // Using sieve
            }
        }
    }
}
vector<int> primeFact(int x){
    vector<int> ans;
    while(x>1){
        ans.push_back(sp[x]);
        x/=sp[x];
    }
    return ans;
}

// phi[i]=Totient function- No. of coprimes between [1,N]
for(int i=1;i<=N;i++){
    phi[i]=i;
}
for(int i=2;i<=N;i++){
    if(is_prime(i)){
        for(int j=i;j<=N;j+=i){
            phi[j]-=phi[j]/i;
        }
    }
}

void solve(){
	
}


signed main(){

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int _t;cin>>_t;while(_t--)
	solve();
}




