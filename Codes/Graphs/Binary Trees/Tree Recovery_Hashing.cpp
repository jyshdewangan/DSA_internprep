// Inorder Preorder tree recovery- Hashing Method

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
struct node{
	int data;
	node *left,*right;
	node(int d){
		data = d;
		left=right=NULL;
	}
};

int n;
vector<char> inorder,preorder;
map<char,int> mp;
node* create(int lin,int rin,int lpre,int rpre){
	if(rin<lin) return NULL;

	int rootval = preorder[lpre];
	int brpoint = mp[rootval];

	node *root = new node(rootval);
	//  Creating left and right trees
	// Inorder array - root lies at brpoint - left side of tree is 
	// left side of brpoint and vice versa
	
	// Preorder array - root lies at the front - left subtree is fron lpre+1 to
	// lpre + (brpoint-lin) and beyond that is right subtree

	root->left = create(lin,brpoint-1,lpre+1,lpre+(brpoint-lin));
	root->right = create(brpoint+1,rin,lpre+(brpoint-lin)+1,rpre);

	return root;
}

void print(node*head){
	if(head==NULL) return;


	print(head->left);
	cout<<(char)head->data<<" ";
	print(head->right);
}
void solve(){
	cin>>n;
	for(int i=0;i<n;i++){
		char a;cin>>a;
		inorder.pb(a);
		mp[a]=i;
	}
	for(int i=0;i<n;i++){
		char a;cin>>a;
		preorder.pb(a);
	}
	node *head = create(0,n-1,0,n-1);
	// cout<<(char)head->data<<" "<<(char)head->left->data<<" "<<(char)head->right->data;
	print(head);
}

signed main(){		
 
	FasFasCrow
	// int _t;	cin>>_t;while(_t--)
	solve();
	// cout<<1;
}

