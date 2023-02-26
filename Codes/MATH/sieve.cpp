
// Sieve of Eratosthenes


#include <bits/stdc++.h>
using namespace std;

const unsigned int M = 1e9 +7;
#define int long long


// Sieve of Eratosthenes
void solve(){
	int n;cin>>n;
    int is_prime[n];
    for(int i=2;i<=n;i++) is_prime[i]=1;
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=n;j+=i){
                is_prime[j]=0;
            }        
        }
    }
}

// Segmented Sieve - find no. of primes between [a,b]
void solve(){
	int a,b;
    int is_prime[n];
    for(int i=2;i<=n;i++) is_prime[i]=1;
    for(int prime:[1,sqrt(b)]){
        long long currMul= ((a+prime-1)/prime)*prime;   // multiple of prime just greater than a, ceil(a/p)*p

        while(currMul>=b){
            if(currMul!=prime){
                is_prime[currMul-a]=0;
                currMul+=prime;
            }
        }
    }
}


signed main(){

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int _t;cin>>_t;while(_t--)
	solve();
}




