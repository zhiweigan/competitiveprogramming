#include <cmath>
#include <queue>
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <stack>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> sparsefin;
vector<int> arr2;

int rmq(int low, int high){
    int l = high-low+1;
    int k = log2(l);
    
    return min(arr2[sparsefin[low][k]], arr2[sparsefin[low+l-pow(2,k)][k]]);
}

vector<vector<int>> make(int input[], int n){
    
    int d = (int)floor(log2(n))+1;
    vector< vector< int > > sparse ( n, std::vector<int> ( d, 0 ) );
    for(int i = 0; i < n; i++){sparse[i][0] = i;}
    for(int j = 1; pow(2,j) <= n; j++){
        for(int i = 0; i + pow(2,j) - 1 < n; i++){
            if(input[sparse[i][j-1]] < input[sparse[i+pow(2,j-1)][j-1]]){
                sparse[i][j] = sparse[i][j-1];
            }
            else{
                sparse[i][j] = sparse[i+pow(2,j-1)][j-1];
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < d; j++){
            cout<<sparse[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return sparse;
}

int main(int argc, const char * argv[]) {
    
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        arr2.push_back(arr[i]);
    }
    
    sparsefin = make(arr, n);
    cout<<rmq(0, n-1)<<endl;
    
    return 0;
}
