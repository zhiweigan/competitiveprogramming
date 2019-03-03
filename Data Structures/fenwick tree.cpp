#include <cmath>
#include <queue>
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;


int n;
vector<int> A;
vector<int> arr;

int sum(int i) // Returns the sum from index 1 to i
{
    int sum = 0;
    while(i > 0)
        sum += A[i-1], i -= i & -i;
    return sum;
}

void add(int i, int k) // Adds k to element with index i
{
    while (i <= n)
        A[i-1] += k, i += i & -i;
    
}

int main(int argc, const char * argv[]) {
    
    cin>>n;
    
    for(int i = 0; i < n; i++){
        A.push_back(0);
    }
    
    for(int i = 0; i < n; i++){
        int temp;
        cin>>temp;
        
        arr.push_back(temp);
        add(i+1, temp);
    }
    for(int i = 0; i < n; i++){
        cerr<<A[i]<<" ";
    }
    cerr<<endl;
    cout<<sum(6)<<endl;
    
    
    return 0;
}
