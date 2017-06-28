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
const long long MOD = 1e9 + 7;
using namespace std;

ll f[100001];

ll pow(ll a, ll b)
{
    ll x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}


ll InverseEuler(ll n)
{
    return pow(n,MOD-2);
}

ll C(ll n, ll r)
{
    
    return (f[n]*((InverseEuler(f[r]) * InverseEuler(f[n-r])) % MOD)) % MOD;
}

int main(){
    f[0] = 1;
    for(int i = 1 ; i <= 100000 ; i++)
        f[i] = (f[i-1]*i)%MOD;
    
    cout << C(10,5) << endl;
}
