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
const int N = 1e6;

int size[N];
int Arr[N];

void initialize(int size[], int Arr[ ], int N)
{
    for(int i = 0;i<N;i++)
    {
        Arr[ i ] = i ;
        size[ i ] = 1;
    }
}

int root (int Arr[ ] ,int i)
{
    while(Arr[ i ] != i)
    {
        Arr[ i ] = Arr[ Arr[ i ] ] ;
        i = Arr[ i ];
    }
    return i;
}

void weightedunio(int A,int B)
{
    int root_A = root(Arr, A);
    int root_B = root(Arr, B);
    if(size[root_A] < size[root_B ])
    {
        Arr[ root_A ] = Arr[root_B];
        size[root_B] += size[root_A];
    }
    else
    {
        Arr[ root_B ] = Arr[root_A];
        size[root_A] += size[root_B];
    }
    
}

bool find(int A,int B)
{
    if( root(Arr, A)==root(Arr, B) )       //if A and B have same root,means they are connected.
        return true;
    else
        return false;
}

struct edge{
    int u,v,c;
};

bool comp(edge a, edge b)   {
    return a.c < b.c;
}

int main(int argc, const char * argv[]) {
    
    int n,m;
    cin>>n>>m;
    vector<edge> edges;
    for(int i = 0; i < m; i++){
        edge temp;
        cin>>temp.u;
        cin>>temp.v;
        cin>>temp.c;
        edges.push_back(temp);
    }
    
    sort(edges.begin(), edges.end(), comp);
    
    
    initialize(size, Arr, n);
    vector<edge> mst;
    int cost = 0;
    int u,v;
    
    
    for(int i = 0; i < m && mst.size()<n-1; i++) {
        u = edges[i].u; v = edges[i].v;
        if(!find(u,v)) {
            weightedunio(u, v);
            mst.push_back(edges[i]);
            cost += edges[i].c;
        }
    }
    
    cout<<cost<<endl;
    for(int i = 0; i < mst.size(); i++){
        cout<<mst[i].u<<" "<<mst[i].v<<endl;
    }
    
    
    return 0;
}
