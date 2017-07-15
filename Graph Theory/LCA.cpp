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

#define MAX_N (1 << 17)
#define MAX_V (1 << 17)
#define INF 1000000
#define REP(i, a, b) for(typeof(a) i=(a); i<(typeof(a))(b); i++)
#define rep(i, b) REP(i, 0, (b))
typedef long long ll;
typedef pair<int, int> pii;
// adjacency list of a graph
vector<int> G[MAX_V];
// the root node
int root;
// number of vertices
int V;
// For lowest common ancestor calculations
int pre_order[2*MAX_V - 1];
int depth[2*MAX_V - 1];
int id[MAX_V];

class SegmentTree {
    int n;
    vector<pii> arr;
    void init(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        rep(i, 2*n - 1) arr.push_back(pii(INF, i));
    }
    // Find the minimum value in the range [a, b)
    // @return - pair (depth, index)
    pii impl_query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return pii(INF, k);
        if (a <= l && r <= b) return arr[k];
        else                  return min(impl_query(a, b, 2*k + 1, l, (l + r)/2),
                                         impl_query(a, b, 2*k + 2, (l + r)/2, r));
    }
    
public:
    SegmentTree(int _n) {
        init(_n);
    }
    SegmentTree(int *arr, int _n) {
        init(_n);
        rep(i, n) update(i, pii(arr[i], i));
    }
    void update(int k, pii a) {
        k += n - 1;
        arr[k] = a;
        while (k > 0) {
            k = (k - 1)/2;
            arr[k] = min(arr[2*k + 1], arr[2*k + 2]);
        }
    }
    int query(int a, int b) {
        pii res = impl_query(a, b, 0, 0, n);
        return res.second;
    }
};
void add_edge(int from, int to) {
    G[from].push_back(to);
}
// v - current node
// p - parent node
// d - current depth
// k - current segment
void dfs(int v, int p, int d, int &k) {
    id[v] = k;
    pre_order[k] = v;
    depth[k++] = d;
    rep(i, G[v].size()) {
        if (G[v][i] != p) {
            dfs(G[v][i], v, d+1, k);
            pre_order[k] = v;
            depth[k++] = d;
        }
    }
}
int lca(int u, int v) {
    int k = 0;
    dfs(root, -1, 0, k);
    SegmentTree st(depth, 2*V - 1);
    return pre_order[st.query(min(id[u], id[v]), max(id[u], id[v]) + 1)];
}
