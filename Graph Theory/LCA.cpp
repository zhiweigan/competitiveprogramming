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


int main(int argc, const char * argv[]) {
    
    cin>>n;
    int parent[1000] = {0};
    for(int i = 0; i < n; i++){
        cin>>parent[i];
    }
    
    int a,b;
    cin>>a>>b;
    vector<int> patha;
    vector<int> pathb;
    
    while(parent[a] != -1){
        patha.push_back(a);
        a = parent[a];
    }
    
    while(parent[b] != -1){
        pathb.push_back(b);
        b = parent[b];
    }
    
    reverse(patha.begin(), patha.end());
    reverse(pathb.begin(), pathb.end());
    
    int i = 0;
    for(; i < min(patha.size(), pathb.size()); i++){
        if(patha[i] != pathb[i]){
            break;
        }
    }
    
    cout<<patha[i-1]<<endl;
    
    return 0;
}
