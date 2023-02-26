
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
int board[9][9];
int possible=0;

bool check(int i,int j, int val){
	for(int k=0;k<9;k++){
		if(k!=j && board[i][k]==val) return 0; // Check for columns
		if(k!=i && board[k][j]==val) return 0; // Check for rows
	}

	// Finding first element of the current cell
	int basex = (i/3)*3;
	int basey = (j/3)*3;

	// Travarcing all elements in that cell via first cell
	for(int delx=0;delx<3;delx++){
		for(int dely=0;dely<3;dely++){
			if(MP(basex+delx,basey+dely)!= MP(i,j) && board[basex+delx][basey+dely]==val){
				return 0;
			}
		}
	}
	return 1;
}

void rec(int i,int j){
	if(i==9){ // If at last row, all other rows are filled, answer is possible
		possible++;
		return;
	}
	if(j==9){ // If at last column, shift to next row and 1st column
		if(!check(i,j,board[i][j])) return; // If current value is invalid, dont go further, OPTIMIZATION
		rec(i+1,0);
	}

	// Choices
	for(int ch=1;ch<=9;ch++){
		if(check(i,j,ch)){
			board[i][j]=ch;
			rec(i,j+1); // Go to next level, next cell
			board[i][j]=0;
		}
	}
}

void solve(){
	
}

signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}