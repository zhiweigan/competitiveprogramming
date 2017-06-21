#include <cmath>
#include <queue>
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <stack>
#include <climits>
#include <assert.h>
#include <set>
#include <queue>
#include <algorithm>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld;


typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;
//const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int dist[N] = {0};
int visited[N] = {0};
vector<int> adj[N];

void bfswithdistance(int s){
    queue<int> bfs;
    dist[s] = 0; //distance to source = 0
    bfs.push(s); //push source to queue
    
    while(!bfs.empty()){
        int current = bfs.front(); //current node
        visited[current] = 1;
        //mark as visited so node isn't visited again, ensures distance marked is shortest distance from source to node
        
        bfs.pop(); //pop current node from queue
        
        for(auto elem:adj[current]){ //for all adjacent nodes
            if(visited[elem] != 1){ //if not visited
                dist[elem] = dist[current] + 1; //distance to adjacent node = distance to current node + 1
                bfs.push(elem);
            }
        }
        
    }
}

void bfs(int s){
    queue<int> bfs;
    dist[s] = 0;
    bfs.push(s);
    while(!bfs.empty()){
        int current = bfs.front();
        visited[current] = 1;
        bfs.pop();
        for(auto elem:adj[current]){
            if(visited[elem] != 1){
                bfs.push(elem);
            }
        }
    }
}


int main(){
    
    
    int n,m;
    cin>>n>>m; //number of nodes, number of edges
    for(int i = 0; i < n; i++){
        dist[i] = INT_MAX;
    }
    
    for(int i = 0; i < m; i++){ //take input for edges
        int u,v;
        cin>>u>>v;
        
        u--; v--; //for 1 indexed graphs
        
        adj[u].push_back(v);
        adj[v].push_back(u); //for bidirectional graphs
        
    }
    int s;
    cin>>s;
    
    bfswithdistance(s-1); //call bfs
    
    for(int i = 0; i < n; i++){
        cout<<"Distance to Node "<<i+1<<": "<<dist[i]<<endl; //print distances to nodes
    }
    
    
}
