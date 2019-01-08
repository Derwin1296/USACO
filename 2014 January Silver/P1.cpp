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
vector<int> T, D;
// Simulate Journey
double solve(){
    double totalTime = 0.0;
    double totalDist = 0.0;
    int denom = 1;
    // Current time, dist pointer
    int curDP = 0; int curTP = 0;
    while(curDP < D.size() || curTP < T.size()){
        double nD = D[curDP];
        double nT = T[curTP];
        // cout << "(" << nD << ", " << nT << ")\n";
        // Time until next dist, Time
        double tTime = curTP < T.size() ? double(nT) - totalTime : INF;
        double dTime = curDP < D.size() ? (nD - totalDist) * denom : INF;
        // cout << "(" << dTime << ", " << tTime << ")\n";
        // T less than or equal to D
        if(tTime <= dTime){
            totalTime = nT;
            curTP ++;
            totalDist += double(tTime) / (denom + 0.00);
        }
        // D less than T
        else if(dTime < tTime){
            totalTime += dTime;
            curDP ++;
            totalDist = nD;
        }
        // Change speed of Bessie
        denom ++;
        cout << "(" << totalDist << ", " << totalTime << ")\n";
    }
    totalTime += 0.5;
    return floor(totalTime);
}
int main() {
    // freopen("slowdown.in", "r", stdin);
    // freopen("slowdown.out", "w", stdout);
    int n; cin >> n;
    F0R(i, n){
        char c; int x;
        cin >> c >> x;
        if(c == 'T'){
            T.pb(x);
        }
        else{
            D.pb(x);
        }
    }
    D.pb(1000);
    sort(all(T));
    sort(all(D));
    double ans = solve();
    cout << ans;
}
