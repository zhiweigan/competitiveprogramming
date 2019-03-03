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

int trie[N][26] = {0};
int endt[N] = {0};

int numofnodes = 0;

void insert(string s){
    
    int curnode = 0;
    for(int i = 0; i < s.size(); i++){
        if(trie[curnode][s[i]-'a'] == 0){
            trie[curnode][s[i]-'a'] = ++numofnodes;
        }
        curnode = trie[curnode][s[i]-'a'];
    }
    
    endt[curnode]++;
    
}

bool search(string s){
    
    int curnode = 0;
    for(int i = 0; i < s.size(); i++){
        if(trie[curnode][s[i]-'a'] == 0){
            return false;
        }
        curnode = trie[curnode][s[i]-'a'];
    }
    
    if(endt[curnode] > 0){
        return true;
    }
    
    return false;
}





int main(int argc, const char * argv[]) {
    
    
    insert("hello");
    insert("heyyo");
    cout<<search("heyyo")<<endl;
    
    
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 26; j++){
            cout<<trie[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}
