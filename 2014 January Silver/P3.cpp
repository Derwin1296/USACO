#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)


#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;
ll grid[510][510];
bool waypoint[510][510];
pi entryPoint;
bool vis[510][510];

int xDir[4] = {1, -1, 0, 0};
int yDir[4] = {0, 0, -1, 1};
// in bounds
bool inBounds(int x, int y, int m, int n){
    return x >= 0 && x < m && y >= 0 && y < n;
}
// bfs
void bfs(pi point, int m, int n, int d){
    int xCoor = point.f; int yCoor = point.s;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            vis[i][j] = false;
        }
    }
    queue<pi> q;
    q.push({xCoor, yCoor});
    while(!q.empty()){
        pi cPair = q.front();
        q.pop();
        int curX = cPair.f; int curY = cPair.s;
        
        vis[curX][curY] = true;
        for(int i = 0; i < 4; i++){
            int newX = curX + xDir[i];
            int newY = curY + yDir[i];
            if(inBounds(newX, newY, m, n) && !vis[newX][newY] && abs(grid[newX][newY] - grid[curX][curY]) <= d){
                vis[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }
}
// waypoints all true
bool allWayPoints(int m, int n, vector<pi> toCheck){
    for(int i = 0; i < toCheck.size(); i++){
        pi cPair = toCheck[i];
        if(!vis[cPair.f][cPair.s]){
            return false;
        }
    }
    return true;
}
int main() {
    vector<pi> wayPoints;
    int M, N; cin >> M >> N;
    F0R(i, M){
        F0R(j, N){
            cin >> grid[i][j];
        }
    }
    F0R(i, M){
        F0R(j, N){
            int x; cin >> x;
            if(x == 1){
                waypoint[i][j] = true;
                entryPoint = {i, j};
                wayPoints.pb({i, j});
            }
        }
    }
    ll low = 0; ll high = 1e9;
    while(low < high){
        ll mid = (low + high) / 2;
        bfs(entryPoint, M, N, mid);
        bool valid = allWayPoints(M, N, wayPoints);
        if(valid){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    cout << low;
}
