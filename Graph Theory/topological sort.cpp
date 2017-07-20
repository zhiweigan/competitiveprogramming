#include <cmath>
#include <queue>
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <stack>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;


int n,m;
vector<int> graph[1000];
int visited[1000]  = {0};
int flag = 0;
vector<int> L;

void visit(int u){
    visited[u] = 1;
    for(int v:graph[u]){
    	if(!visited[v]){
    		visit(v);
    	}
    }
    L.push_back(u);
}

vector<int> toposort(){
    
    for(int i = 0; i < n; i++){
    	if(!visited[i]){
    		visit(i);
    	}
    }
    
    return L;
    
}


int main(int argc, const char * argv[]) {
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int a,b;
        cin>>a>>b; a--; b--;
        graph[a].push_back(b);
    }
    
    toposort();
    reverse(L.begin(), L.end());
    
    for(int i = 0; i < L.size(); i++){
        cout<<L[i]<<endl;
    }
    
    return 0;
}
