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
int distsq(ii p1, ii p2){
    return pow(p1.first-p2.first,2) + pow(p1.second-p2.second,2);
}
//checks the gradients, and returns 1 if a clockwise turn is found, and 2 if it is counterclockwise. 0 is returned if collinear.
int orientation(ii p1, ii p2, ii p3){
    int diff = (p1.second-p2.second) * (p2.first-p3.first) - (p2.second-p3.second)*(p1.first-p2.first);
    if(diff == 0) return 0;
    if(diff > 0) return 1;
    return 2;
}

ii p0;
//comparative function for sorting, if it is counterclockwise, return 1, and 0 if not.

int compare(ii p1, ii p2){
    int o = orientation(p0, p1, p2);
    if(o == 0) //if collinear
        return distsq(p0, p2) < distsq(p0, p1); //return 1 if p2 is closer than p1 i.e. if the point is closer, make it appear closer to the front of the array after sorting
    return o == 2; //if counterclockwise, return 1.
}

stack<ii> convexhull(vector<ii> points){
    stack<ii> S;
    
    
    //if there are less than 3 points, return an empty stack because a convex hull cannot be formed.
    if(points.size() < 3){
        return S;
    }
    
    //find the bottommost, then leftmost point of the points to act as a pivot for sorting.
    
    int ymin = points[0].second, min = 0;
    for (int i = 1; i < points.size(); i++)
    {
        int y = points[i].second;
        
        if ((y < ymin) || (ymin == y && points[i].first < points[min].first))
            ymin = points[i].second, min = i;
    }
    
    
    
    p0.first = points[min].first;
    p0.second = points[min].second;
    points[min] = points[0];
    points[0].first = p0.first;
    points[0].second = p0.second;
    
    
    sort(points.begin()+1, points.end(), compare);
    
    //sort points in an anticlockwise manner.
    
    //push the first 3 points into the stack.
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);
    
    for(int i = 3; i < points.size(); i++){
        ii top = S.top();
        S.pop();
        while(orientation(S.top(), top, points[i]) != 2){ //keep removing points from the stack while the orientation of the 3 points is not counterclockwise (ie.) remove the point from the temporary convex hull that creates a non-convex shape.
            top = S.top();
            S.pop();
        }
        S.push(top);
        S.push(points[i]);
    }
    
    
    
    return S;
}


int main(){
    
    
    
    int n;
    cin>>n;
    vector<ii> points;
    for(int i = 0; i < n; i++){
        int x,y;
        cin>>x>>y;
        points.push_back(mp(x,y));
    }
    
    
    
    stack<ii> S = convexhull(points);
    //print stack
    while(S.size() > 0){
        cout<<S.top().first<<", "<<S.top().second<<endl;
        S.pop();
    }
    
    
}
