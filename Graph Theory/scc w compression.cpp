#include <cmath>
#include <queue>
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <stack>
#include <climits>
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
const int N = 100001;
const int MOD = 1e9 + 7;

stack<int> sccstack;
vector<int> adj[N];
vector<int> reversedadj[N];
int visited[N] = {0};
int visited2[N] = {0};

void dfs(int node){
    
    visited[node] = 1;
    
    for(auto elem:adj[node]){
        if(!visited[elem])
            dfs(elem);
    }
    
    sccstack.push(node);
}

int sccid[N];

void dfs2(int node, int i){
    
    visited2[node] = 1;
    sccid[node] = i;
    
    for(auto elem:reversedadj[node]){
        if(!visited2[elem])
            dfs2(elem, i);
    }
    
}



int main(int argc, const char * argv[]) {
    
    int n,m;
    cin>>n>>m;
    
    for(int i = 0; i < m; i++){
        int a,b;
        cin>>a>>b; a--; b--;
        adj[a].push_back(b);
        reversedadj[b].push_back(a);
    }
    
    for(int i = 0; i < n; i++){
        if(!visited[i])
            dfs(i);
    }
    int z = 0;
    while(!sccstack.empty()){
        if(visited2[sccstack.top()] == 0){
            dfs2(sccstack.top(), z);
            z++;
        }
        else{
            sccstack.pop();
        }
    }
    
    
    vector<int> newadj[N];
    
    for(int i = 0; i < n; i++){
        for(auto elem:adj[i]){
            if(sccid[i] != sccid[elem]){
                newadj[sccid[i]].push_back(sccid[elem]);
                cerr<<i<<" "<<elem<<endl;
            }
        }
    }
    
    
    
    return 0;
}
