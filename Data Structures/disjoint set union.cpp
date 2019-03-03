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

/*modified union function where we connect the elements by changing the root of one of the element */
/*
void unio(int Arr[ ] ,int A ,int B)
{
    int root_A = root(Arr, A);
    int root_B = root(Arr, B);
    Arr[ root_A ] = root_B ;       //setting parent of root(A) as root(B).
}
*/

void weightedunio(int Arr[ ],int size[ ],int A,int B)
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

bool find(int Arr[], int A,int B)
{
    if( root(Arr, A)==root(Arr, B) )       //if A and B have same root,means they are connected.
        return true;
    else
        return false;
}

int main(int argc, const char * argv[]) {
    
    int arr[5] = {0,1,2,3,4};
    int size[5] = {1,1,1,1,1};
    
    weightedunio(arr, size, 0, 1);
    cout<<find(arr, 0, 1)<<endl;
    
    
    return 0;
}
