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
struct edge{ //edge struct
    int u,v,c;
};


vector<edge> edges;
int n,m;

int bellmanford(int s){
    //initialise distances
    for(int i = 0; i < n; i++){
        dist[i] = INT_MAX;
    }
    dist[s] = 0; //distance to source is 0;
    
    //relax edges n-1 times
    for(int i = 0; i < n-1; i++){
        for(auto edge:edges){
            if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.c < dist[edge.v]){
                dist[edge.v] = dist[edge.u] + edge.c; //relaxing if distance using this edge is shorter
            }
        }
    }
    
    //check for negative weight edge cycle
    for(auto edge:edges){
        if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.c < dist[edge.v]){
            return 1;
        }
        
    }
    
    return 0;
    
}

int main(){
    
    
    
    cin>>n>>m; //number of nodes, number of edges
    
    
    for(int i = 0; i < m; i++){ //take input for edges, bidirectional.
        int u,v,c;
        cin>>u>>v>>c; u--;v--;
        edge temp;
        temp.u = u;
        temp.v = v;
        temp.c = c;
        edge temp2;
        temp2.u = v;
        temp2.v = u;
        temp2.c = c;
        
        edges.push_back(temp);
        edges.push_back(temp2);
    }
    int s; //source
    cin>>s;
    
    if(bellmanford(s-1)){ //bellman-ford only works if there are no negative weight edge cycles.
        cout<<"Contains negative weight edge cycle"<<endl;
    }
    else{
        for(int i = 0; i < n; i++){
            cout<<"Distance to Node "<<i+1<<": "<<dist[i]<<endl;
        }
    }
    
    
}
