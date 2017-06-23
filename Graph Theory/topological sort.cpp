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

void visit(int s){
    if(visited[s] == 2){
        flag = 1;
    }
    if(visited[s] == 0){
        visited[s] = 2;
        for(int elem:graph[s]){
            visit(elem);
        }
        visited[s] = 1;
        L.push_back(s);
    }
    
    
}

vector<int> toposort(){
    
    
    
    
    
    while(flag == 0){
        int s = 0;
        int internalflag = 0;
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                internalflag = 1;
                s = i;
                break;
            }
        }
        if(internalflag == 1){
            flag = 1;
        }
        
        visit(s);
    }
    
    
    
    return L;
    
    
}


int main(int argc, const char * argv[]) {
    
    cin>>n;
    for(int i = 0; i < n-1; i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    
    visit(0);
    reverse(L.begin(), L.end());
    
    for(int i = 0; i < L.size(); i++){
        cout<<L[i]<<endl;
    }
    
    return 0;
}
