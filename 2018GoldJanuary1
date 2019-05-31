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
int snakes[410];
int sparse[410][410];
ll dpt[410][410]; // dpt[n][k] = start at position n, with k switches remaining
// Calculates max query
int maxQuery(int a, int b){
    int j =  (int)(log2(b - a + 1));
    return max(sparse[a][j], sparse[b - (1 << j) + 1][j]);
}
// Given current maximum, calculate wasted spaces
ll wastedSpaces(int L, int R, int max){
    ll total = 0;
    FOR(i, L, R + 1){
        total += (ll)(max - snakes[i]);
    }
    return total;
}
// Calculates dp table
ll dp(int pos, int sRem, int N){
    // No switches remain
    if(sRem == 0){
        // Maximum, calculated wasted space
        int m = maxQuery(pos, N - 1);
        return wastedSpaces(pos, N - 1, m);
    }
    // Pos extremely right
    else if(N - 1 - pos <= sRem){
        return 0;
    }
    // Already calculated:
    else if(dpt[pos][sRem] != -1){
        return dpt[pos][sRem];
    }
    else{
        ll curMin = -1;
        for(int newPos = pos + 1; newPos < N; newPos++){
            // Range [pos, newPos - 1], const = wastedSpace(range, maxQ(range))
            int rangeMax = maxQuery(pos, newPos - 1);
            ll c = wastedSpaces(pos, newPos - 1, rangeMax);
            // Next DP calculated
            ll nextDP = dp(newPos, sRem - 1, N);
            // Recalculated minimum
            if(curMin == -1 || curMin > nextDP + c){
                curMin = nextDP + c;
            }
        }
        return curMin;
    }
}
int main() {
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    int N, K;
    cin >> N >> K;
    F0R(i, N){
        cin >> snakes[i];
    }
    // Build sparse table:
    for(int i = 0; i < N; i++){
        sparse[i][0] = snakes[i];
    }
    // Smallest to largest intervals
    for(int j = 1; (1 << j) <= N; j++){
        // All intervals with 2^j
        for(int i = 0; (i + (1 << j) - 1) < N; i++){
            if(sparse[i][j - 1] < sparse[i + (1 << (j - 1))][j - 1]){
                sparse[i][j] = sparse[i + (1 << (j - 1))][j - 1];
            }
            else{
                sparse[i][j] = sparse[i][j - 1];
            }
        }
    }
    // DP table all -1
    F0R(i, N){
        F0R(j, K + 1){
            dpt[i][j] = -1;
        }
    }
    // Forms the DP table
    for(int sRem = 0; sRem <= K; sRem ++){
        for(int pos = N - 1; pos >= 0; pos--){
            dpt[pos][sRem] = dp(pos, sRem, N);
        }
    }
    ll ans = dpt[0][K];
    cout << ans;
    // F0R(i, N){
    //     F0R(j, K + 1){
    //         cout << dpt[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << ans;
    // Test:
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; (i + (1 << j) - 1) < N; j++){
    //         cout << "Current range: " << i << ", " << j << ": " << sparse[i][j] << "\n";
    //     }
    // }
}
