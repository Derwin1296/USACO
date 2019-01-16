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
vector<pair<ll, int>> adjList[260];
int parent[260];
ll dist[260];
bool vis[260];
ll adjMatrix[260][260];
// Shortest path with heap
void dijkstra(int vertex){
    set<pair<ll, int>> toProcess;
    toProcess.insert({0, vertex});
    dist[0] = 0;
    while(!toProcess.empty()){
        pair<ll, int> p = *toProcess.begin();
        ll curDist = p.f;
        int curV = p.s;
        // Relax vertex, visit neighbors
        toProcess.erase(toProcess.begin());
        vis[curV] = true;
        vector<pair<ll, int>> n = adjList[curV];
        for(int i = 0; i < n.size(); i++){
            pair<ll, int> data = n[i];
            int adjV = data.s; ll d = adjMatrix[adjV][curV];
            if(!vis[adjV]){
                if(curDist + d < dist[adjV]){
                    dist[adjV] = curDist + d;
                    parent[adjV] = curV;
                    toProcess.insert({dist[adjV], adjV});
                }
            }
        }
    }
}
// Finds second max distance
ll newDist(int n){
    ll bestNewDist = -1;
    int curV = n; int curP = parent[curV];
    while(curP != -1){
        adjMatrix[curV][curP] *= 2;
        adjMatrix[curP][curV] *= 2;
        // Reset to initial conditions
        for(int i = 0; i < 260; i++){
            dist[i] = INF;
            vis[i] = false;
        }
        dijkstra(0);
        bestNewDist = max(bestNewDist, dist[n]);
        // Change parent, vertex, switch back edge length
        adjMatrix[curV][curP] /= 2;
        adjMatrix[curP][curV] /= 2;
        curV = curP;
        curP = parent[curV];
    }
    return bestNewDist;
}
int main() {
    freopen("rblock.in", "r", stdin);
    freopen("rblock.out", "w", stdout);
    memset(parent, -1, sizeof(parent));
    for(int i = 0; i < 260; i++){
        dist[i] = INF;
    }
    for(int i = 0; i < 260; i++){
        for(int j = 0; j < 260; j++){
            if(i != j){
                adjMatrix[i][j] = INF;
                adjMatrix[j][i] = INF;
            }
            else{
                adjMatrix[i][j] = 0;
            }
        }
    }
    int n, m;
    cin >> n >> m;
    F0R(i, m){
        int a, b; ll L;
        cin >> a >> b >> L;
        a--; b--;
        adjList[a].pb({L, b}); adjList[b].pb({L, a});
        adjMatrix[a][b] = L; adjMatrix[b][a] = L;
    }
    dijkstra(0);
    ll firstAns = dist[n - 1];
    ll secondAns = newDist(n - 1);
    cout << (secondAns - firstAns);
}
