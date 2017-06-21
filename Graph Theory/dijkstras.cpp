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
vector<int> adj[N];
vector<int> weights[N];

//compare function so node with minimum distance appears on the top

class CompareDist
{
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2) {
        return n1.second>n2.second; //compares second value in pair.
    }
};

void dijkstra(int start)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,CompareDist> pq;
    //by default, priority queue would sort by greatest element. http://en.cppreference.com/w/cpp/container/priority_queue
    
    
    dist[start] = 0; //distance to source node = 0
    pq.push(make_pair(start, dist[start]));
    
    while(!pq.empty()){
        auto u = pq.top().first;
        //take element with shortest distance in priority queue (greedy)
        pq.pop();
        
        //for each node that is adjacent to <u>
        for(int i = 0; i < adj[u].size(); i++){
            int elem = adj[u][i];
            int alt = dist[u] + weights[u][i]; //distance to elem if edge u,elem is used.
            //if distance is shorter than current distance to element using this edge
            if(alt < dist[elem]){
                dist[elem] = alt; //set new distance
                pq.push(make_pair(elem, alt));
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
        int u,v,c;
        cin>>u>>v>>c;
        
        u--; v--; //for 1 indexed graphs
        
        adj[u].push_back(v);
        adj[v].push_back(u); //for bidirectional graphs
        weights[u].push_back(c);
        weights[v].push_back(c);
        
    }
    int s; //source
    cin>>s;
    
    dijkstra(s-1);
    
    for(int i = 0; i < n; i++){
        cout<<"Distance to Node "<<i+1<<": "<<dist[i]<<endl;
    }
    
    
}
