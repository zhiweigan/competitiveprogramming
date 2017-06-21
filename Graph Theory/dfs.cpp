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

void dfsstack(int s){
    stack<int> dfs;
    dfs.push(s);
    while(!dfs.empty()){ //while there are still nodes to be visited
        int current = dfs.top(); //pick node that was last put into the stack
        cout<<"Visiting Node: "<<current+1<<endl;
        visited[current] = 1;
        dfs.pop();
        for(auto elem:adj[current]){ //for all adjacent nodes
            if(visited[elem] != 1){
                dfs.push(elem);
            }
        }
    }
}

void dfsrecur(int s){
    visited[s] = 1;
    cout<<"Visiting Node: "<<s+1<<endl;
    for(auto elem:adj[s]){ //recursively call dfs on adjacent nodes
        if(visited[elem] != 1){
            dfsrecur(elem);
        }
    }
}


int main(){
    
    
    int n,m;
    cin>>n>>m; //number of nodes, number of edges
    
    
    for(int i = 0; i < m; i++){ //take input for edges
        int u,v;
        cin>>u>>v;
        
        u--; v--; //for 1 indexed graphs
        
        adj[u].push_back(v);
        adj[v].push_back(u); //for bidirectional graphs
        
    }
    int s; //source
    cin>>s;
    
    dfsrecur(s-1); //call dfs
    
    
    
}
