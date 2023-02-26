// Q. find the shortest path between start and end. 
/*
6 6
S.#...
......
####.#
E.##.#
..#..#
#....#
*/
#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

using ii = pair<int,int>;
int n,m;
vector<string> arr;
int dist[1010][1010];
ii par[1010][1010]; // Parent pair for printing path

// If we were to move all 8 neighbors of any cell
// int dx[] = {1,1,1,0,-1,-1,-1,0};
// int dy[] = {1,0,-1,-1,-1,0,1,1};

// for piece is a knight
// int dx[] = {2,1,-1,-2,-2,-1,1,2};
// int dy[] = {-1,-2,-2,-1,1,2,2,1};

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool inside(int x, int y){
    if(x<0 || x>=n || y<0 || y>=m || arr[x][y]=='#') return 0;
    else return 1;
}


void bfs(ii st){
    // Initialisation distance matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j] = 1e9;
        }
    }

    // Putting initial distance == 0
    dist[st.F][st.S]=0;
    // making queue and then starting to push all nodes and their neighbours till queue isn't empty 
    queue<ii> q;
    q.push(st);
    while(!q.empty()){
        ii curr = q.front();
        q.pop();
        int curd = dist[curr.F][curr.S];
        // Loop over all valid neighbors of current node
        for(int k=0;k<4;k++){
            ii neigh = {curr.F+dx[k],curr.S+dy[k]};
            if(!inside(neigh.F,neigh.S)) continue;
            // initially dist[neigh.F][neigh.S] is 1e9 which is greater. dist array is more like visited array in dfs.
            if(dist[neigh.F][neigh.S] > curd + 1){ // Relax
                dist[neigh.F][neigh.S] = curd + 1;
                par[neigh.F][neigh.S] = curr;
                q.push(neigh);
            }
        }
    }
}

int main(){
    cin>>n>>m;
    arr.resize(n);
    ii st,en;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<m;j++){
            if(arr[i][j]=='S') st = {i,j};
            else if(arr[i][j]=='E') en={i,j};
        }
    }
    bfs(st);
    cout<<dist[en.F][en.S]<<"\n"; // To print min distance


    // To print distance matrix

    // for(int i=0;i<n;i++){ 
    //     for(int j=0;j<m;j++){
    //         cout<<dist[i][j]<<"\t";
    //     }
    //     cout<<"\n";
    // }

    // For Printing path

    // ii temp = en;
    // vector<ii> path;
    // while(temp!=st){
    //     path.push_back(temp);
    //     temp = par[temp.F][temp.S];
    // }
    // path.push_back(st);
    // reverse(path.begin(),path.end());
    // for(auto v:path){
    //     cout<<v.F<<" "<<v.S<<"\n";
    // }

    // if (!used[u]) {
    // cout << "No path!";
    // } else {
    // vector<int> path;
    // for (int v = u; v != -1; v = p[v])
    //     path.push_back(v);
    // reverse(path.begin(), path.end());
    // cout << "Path: ";
    // for (int v : path)
    //     cout << v << " ";
    // }
}