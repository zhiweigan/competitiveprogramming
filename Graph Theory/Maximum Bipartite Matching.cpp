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

int visited[N] = {0};
vector<int> adj[N];
int n,m,k;
int matchR[N];

bool bpm(int u )
{
    // Try every job one by one
    for (auto elem:adj[u])
    {
        // If applicant u is interested in job v and v is
        // not visited
        if (!visited[elem])
        {
            visited[elem] = true;
            
            if (matchR[elem] < 0 || bpm(u))
            {
                matchR[elem] = u;
                return true;
            }
        }
    }
    return false;
}

// Returns maximum number of matching from M to N
int maxBPM()
{
    // An array to keep track of the applicants assigned to
    // jobs. The value of matchR[i] is the applicant number
    // assigned to job i, the value -1 indicates nobody is
    // assigned.
    
    // Initially all jobs are available
    memset(matchR, -1, sizeof(matchR));
    
    int result = 0; // Count of jobs assigned to applicants
    for (int u = 0; u < k; u++)
    {
        // Mark all jobs as not seen for next applicant.
        memset(visited, 0, sizeof(visited));
        
        // Find if the applicant 'u' can get a job
        if (bpm(u))
            result++;
    }
    return result;
}



int main(){
    
    
    
    cin>>n>>m>>k;//number of nodes, number of edges
    
    
    for(int i = 0; i < m; i++){ //take input for edges
        int u,v;
        cin>>u>>v;
        
        u--; v--; //for 1 indexed graphs
        
        adj[u].push_back(v);
        adj[v].push_back(u);
        //for bidirectional graphs
        
    }
    
    
    int a = maxBPM();
    cout<<a<<endl;
    
    
}
