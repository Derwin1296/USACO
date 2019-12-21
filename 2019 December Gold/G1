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

int flow_matrix[1001][1001];
int cost_matrix[1001][1001];
vi v[1001];
ll min_dist[1001];
bool visited[1001];
int par[1001];


// Find closest vertex for Dijkstra
int find_close(int n){
    ll low = -1;
    int ind = -1;
    F0R(i, n){
        if((min_dist[i] < low || low == -1) && !visited[i]){
            low = min_dist[i];
            ind = i;
        }
    }
    return ind;
}
void reset(int n){
    min_dist[0] = 0;
    par[0] = 0;
    visited[0] = false;
    FOR(i, 1, n){
        min_dist[i] = INF;
        visited[i] = false;
        par[i] = i;
    }
}
// Perform Dijkstra
void dstra(int min_f, int n){
    reset(n);
    F0R(i, n){
        // Find closest vertex and visit
        int u = find_close(n);
        visited[u] = true;
        // Modify neighbors
        vi neighbors = v[u];
        for(int j = 0; j < neighbors.size(); j++){
            int adj = neighbors[j];
            // cout << adj << " " << min_dist[adj] << "\n";
            if(min_dist[adj] > min_dist[u] + (ll) cost_matrix[u][adj] && flow_matrix[u][adj] >= min_f){
                min_dist[adj] = min_dist[u] + (ll) cost_matrix[u][adj];
                par[adj] = u;
            }
        }
    }
}
// Finds min flow rate along a path
int find_min_flow(int n){
    int mfr = -1;
    while(n != par[n]){
        // Update min_flow_rate 
        if(flow_matrix[n][par[n]] < mfr || mfr == -1){
            mfr = flow_matrix[n][par[n]];
        }
        n = par[n];
    }
    // No path could be formed
    if(n != 0){
        return 0;
    }
    return mfr;
}
int main()
{
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    F0R(i, m){
        int a, b, c, f;
        cin >> a >> b >> c >> f;
        a--; b--;
        flow_matrix[a][b] = f;
        flow_matrix[b][a] = f;
        cost_matrix[a][b] = c;
        cost_matrix[b][a] = c;
        v[a].pb(b);
        v[b].pb(a);
    }
    ll best_ans = -1;
    // Current min flow rate
    ll cur_min_f = 0;
    while(cur_min_f <= 1000){
        // Perform Dijkstra, update best answer
        dstra(cur_min_f, n);
        int m_f_r = find_min_flow(n - 1);
        best_ans = max(best_ans, (ll)(1000000) * (ll)(m_f_r) / (ll)(min_dist[n - 1]));
        if(m_f_r == 0){
            break;
        }
        cur_min_f = m_f_r + 1;
    }
    cout << best_ans;
}
