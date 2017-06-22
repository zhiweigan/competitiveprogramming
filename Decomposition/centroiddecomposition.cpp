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

int visited[N] = {0};
vector<int> adj[N];
int n,m;
int subtreesizes[N] = {0};
int parents[N] = {0};

//find subtree sizes, traverse if and only if adjacent edge is not parent and edge is not already parent
void dfs(int cur, int p){
    subtreesizes[cur] = 1;
    
    for(int i = 0;i < adj[cur].size();++i){
        int to = adj[cur][i];
        
        if(to != p && parents[to] == -1){
            dfs(to,cur);
            subtreesizes[cur] += subtreesizes[to];
        }
    }
}

//recursively find centroid of graph, splitting the graph each time a centroid is found.
void findcentroid(int cur, int p, int n, int prevc){
    
    for(int i = 0;i < adj[cur].size();i++){
        int to = adj[cur][i];
        
        if(to != p && parents[to] == -1 && 2 * subtreesizes[to] > n){
            findcentroid(to,cur,n,prevc);
            return;
        }
    }
    parents[cur] = prevc;
    
    for(int i = 0;i < adj[cur].size();i++){
        int to = adj[cur][i];
        
        if(parents[to] == -1){
            dfs(to,p);
            findcentroid(to,cur,subtreesizes[to],cur);
        }
    }
    
    
}


int main(){
    
    
    
    cin>>n;//number of nodes, number of edges
    
    
    for(int i = 0; i < n-1; i++){ //take input for edges
        int u,v;
        cin>>u>>v;
        
        u--; v--; //for 1 indexed graphs
        
        adj[u].push_back(v);
        adj[v].push_back(u);
        //for bidirectional graphs
        
    }
    
    
    
    for(int i = 0; i < n; i++){
        parents[i] = -1;
    }
    dfs(0,-1);
    
    findcentroid(0, -1, subtreesizes[0], -2);
    
    for(int i = 0; i < n; i++){
        cout<<parents[i]<<" ";
    }
    
    
    
}
