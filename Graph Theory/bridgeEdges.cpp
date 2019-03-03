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

int visited[N] = {0}, low[N] = {0}, parent[N] = {0}, disc[N] = {0};
vector<int> adj[N];
int n,m;

int t = 0;

void Bridgefinder(int s){
    visited[s] = 1;
    disc[s] = low[s] = t;
    t++;
    for(auto v:adj[s]){
        if(!visited[v]){
            parent[v] = s;
            Bridgefinder(v);
            low[s] = min(low[s], low[v]);
            if (low[v] > disc[s])
                cout << s <<" " << v << endl;
        }
        else if(parent[s] != v){
            low[s]  = min(low[s], disc[v]);
        }
    }
    
    
}

int main(){
    
    
    
    cin>>n>>m;//number of nodes, number of edges
    
    
    for(int i = 0; i < m; i++){ //take input for edges
        int u,v;
        cin>>u>>v;
        
        u--; v--; //for 1 indexed graphs
        
        adj[u].push_back(v);
        adj[v].push_back(u);
        //for bidirectional graphs
        
    }
    memset(parent, -1, sizeof(int) * n);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            Bridgefinder(i);
        }
    }
}
