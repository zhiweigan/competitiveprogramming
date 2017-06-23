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

vector<ii> fadj[N];
int inMST[N] = {0};
int key[N] = {0};
ii parent[N];

void addEdge(int u, int v, int w){
    fadj[u].push_back(mp(v,w));
    fadj[v].push_back(mp(u,w));
}

class CompareDist
{
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2) {
        return n1.second>n2.second;
    }
};

void prims(int start)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,CompareDist> pq;
    
    key[start] = 0;
    
    pq.push(make_pair(start, key[start]));
    
    while(!pq.empty()){
        auto u = pq.top().first;
        
        pq.pop();
        
        inMST[u] = 1;
        
        for(int i = 0; i < fadj[u].size(); i++){
            int elem = fadj[u][i].first;
            int alt = fadj[u][i].second;
            if(alt < key[elem] && inMST[elem] == 0){
                key[elem] = alt;
                pq.push(make_pair(elem, alt));
                parent[elem].first = u;
                parent[elem].second = alt;
            }
        }
        
        
    }
    
}


int main(int argc, const char * argv[]) {
    
    addEdge(0, 1, 4);
    addEdge(0, 7, 8);
    addEdge(1, 2, 8);
    addEdge(1, 7, 11);
    addEdge(2, 3, 7);
    addEdge(2, 8, 2);
    addEdge(2, 5, 4);
    addEdge(3, 4, 9);
    addEdge(3, 5, 14);
    addEdge(4, 5, 10);
    addEdge(5, 6, 2);
    addEdge(6, 7, 1);
    addEdge(6, 8, 6);
    addEdge(7, 8, 7);
    
    for(int i = 0; i < 12; i++){
        key[i] = 100000000;
    }
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < fadj[i].size(); j++){
            cout<<fadj[i][j].second<<" ";
        }
        cout<<endl;
    }
    
    
    prims(0);
    int sum = 0;
    
    for(int i = 1; i < 9; i++){
        cout<<i<<": "<<parent[i].first<<endl;
        sum += parent[i].second;
    }
    cout<<sum<<endl;
    
    
    
    return 0;
}
