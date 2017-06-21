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
const int N = 1e3 + 5;

int dist[N][N] = {0};
int adjm[N][N] = {0};

int n,m;

void floydwarshall(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = adjm[i][j];
        }
    }
    
    for(int z = 0; z < n; z++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (dist[i][z] + dist[z][j] < dist[i][j]){
                    dist[i][j] = dist[i][z] + dist[z][j]; //essentially saying that if there is a route from i to j bypassing node z that is shorter than the original distance between i and j, update the distance using the weights from i-z and z-j.
                }
            }
        }
    }
    
}

int main(){
    
    
    
    cin>>n>>m; //number of nodes, number of edges
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j){
                adjm[i][j] = 99999;
            }
        }
    }
    
    for(int i = 0; i < m; i++){ //take input for edges, bidirectional.
        int u,v,c;
        cin>>u>>v>>c; u--;v--;
        adjm[u][v] = c;
        adjm[v][u] = c;
    }
    
    floydwarshall();
    
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<"Distance from node "<<i+1<<" to node "<<j+1<<": "<<dist[i][j]<<endl;
        }
    }
    
    
    
}
