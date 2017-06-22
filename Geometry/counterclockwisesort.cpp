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

//measures the squared distance between p1 and p2.
int distsq(pair<int,int> p1, pair<int,int> p2){
    return pow(p1.first-p2.first,2) + pow(p1.second-p2.second,2);
}
//checks the gradients, and returns 1 if a clockwise turn is found, and 2 if it is counterclockwise. 0 is returned if collinear.
int orientation(pair<int,int> p1, pair<int,int> p2, pair<int,int> p3){
    int diff = (p1.second-p2.second) * (p2.first-p3.first) - (p2.second-p3.second)*(p1.first-p2.first);
    if(diff == 0) return 0;
    if(diff > 0) return 1;
    return 2;
}

pair<int,int> p0;
//comparative function for sorting, if it is counterclockwise, return 1, and 0 if not.
int compare(pair<int,int> p1, pair<int,int> p2){
    int o = orientation(p0, p1, p2);
    if(o == 0) //if collinear
        return distsq(p0, p2) < distsq(p0, p1); //return 1 if p2 is closer than p1 i.e. if the point is closer, make it appear closer to the front of the array after sorting
    return o == 2; //if clockwise, return 0.
}



int main(){
    
    
    
    int n;
    cin>>n;
    vector<pair<int,int>> points;
    for(int i = 0; i < n; i++){
        int x,y;
        cin>>x>>y;
        points.push_back(mp(x,y));
    }
    
    //find the bottom most point, and if there are more than 1, pick the one closer to the left.
    
    int ymin = points[0].second, min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].second;
        
        // Pick the bottom-most or chose the left
        // most point in case of tie
        if ((y < ymin) || (ymin == y &&
                           points[i].first < points[min].first))
            ymin = points[i].second, min = i;
    }
    
    
    
    p0.first = points[min].first;
    p0.second = points[min].second;
    
    //set this as comparative "anchor"
    
    //sort
    sort(points.begin(), points.end(), compare);
    
    for(int i = 0; i < n; i++){
        cout<<points[i].first<<" "<<points[i].second<<endl;
    }
    
    
    
}
