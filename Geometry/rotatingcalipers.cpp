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
const double pi = 3.14159265359;


//struct for a caliper which has 3 member functions.
struct caliper {
    ii pt;
    double angle;
    caliper(ii _pt, double _angle) : pt(_pt), angle(_angle) { }
    double angle_to(ii pt2) {
        double x = angle - atan2(pt2.second - pt.second,
                                 pt2.first - pt.first);
        while (x >= pi) x -= 2*pi;
        while (x <= -pi) x += 2*pi;
        return x; }
    void rotate(double by) {
        angle -= by;
        while (angle < 0) angle += 2*pi; }
    void move_to(ii pt2) { pt = pt2; }
    
    
};

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
    return o == 1; //if clockwise, return 0.
}



int main(){
    
    
    
    int n;
    cin>>n;
    vector<ii> hull;
    for(int i = 0; i < n; i++){
        int x,y;
        cin>>x>>y;
        hull.push_back(mp(x,y));
    }
    
    //take input from hull
    
    int ymin = hull[0].second, min1 = 0;
    for (int i = 1; i < n; i++)
    {
        int y = hull[i].second;
        
        // Pick the bottom-most or chose the left
        // most point in case of tie
        if ((y < ymin) || (ymin == y &&
                           hull[i].first < hull[min1].first))
            ymin = hull[i].second, min1 = i;
    }
    
    
    
    p0.first = hull[min1].first;
    p0.second = hull[min1].second;
    
    //set this as comparative "anchor"
    
    //sort hull points in clockwise manner
    sort(hull.begin(), hull.end(), compare);
    
    
    //find all antipodal points
    
    if(n > 1){
        int a = 0, b = 0;
        for(int i = 0; i < n; i++){
            if(hull[i].first < hull[a].first){
                a = i;
            }
            if(hull[i].first > hull[b].first){
                b = i;
            }
        }
        
        //define calipers A and B
        caliper A(hull[a], pi/2), B(hull[b], 3*pi/2);
        
        double done = 0;
        
        while(1){
            //find the angle needed to move calipers A and B by to maintain the antipodal nature
            double tha = A.angle_to(hull[(a+1)%n]);
            double thb = B.angle_to(hull[(b+1)%n]);
            
            //rotate by the smallest amount for the antipodal point
            if (tha <= thb) {
                A.rotate(tha);
                B.rotate(tha);
                a = (a+1) % n;
                A.move_to(hull[a]);
            } else {
                A.rotate(thb);
                B.rotate(thb);
                b = (b+1) % n;
                B.move_to(hull[b]);
            }
            
            //prints all antipodal pairs
            cout<<"A: "<<hull[a].first<<", "<<hull[a].second<<" || B: "<<hull[b].first<<", "<<hull[b].second<<endl;
            
            //after rotating 180 degrees, it has reached the the angle of caliper B at the first run, and thus is redundant.
            done += min(tha, thb);
            if (done > pi) {
                break;
            }
            
            
        }
    }
    
    
    return 0;
    
    
    
}
