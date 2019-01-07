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

struct BIT{
    int tree[MX + 10];
    int size;
    // Creates tree with given size
    BIT(int n){
        size = n + 1;
    }
    // Updates tree
    void update(int k, int x){// k = index, x = value
        while(k <= size){
            tree[k] += x;
            k += (k & -k);
        }
    }
    // Find sum 1 to k
    int sum(int k){
        int s = 0;
        while(k >= 1){
            s += tree[k];
            k -= (k & -k);
        }
        return s;
    }
};
struct cow{
  int index;
  int height;
  cow(int h, int i){
      height = h;
      index = i;
  }
  bool operator<(const cow& d) const{
    return height > d.height;
  }
};

vector<cow> cows;
int main() {
    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int height; cin >> height;
        cow c = cow(height, i);
        cows.pb(c);
    }
    sort(cows.begin(), cows.end());
    int ans = 0;
    int cowsAdded = 0;
    // BIT
    BIT bitTree = BIT(n);
    
    for(int i = 0; i < n; i++){
        cow c = cows[i];
        int ind = c.index;
        // Add cows
        cowsAdded ++;
        // Update
        bitTree.update(ind, 1);
        // Find left cows greater and right cows greater
        int leftCows = bitTree.sum(ind) - 1;
        int rightCows = cowsAdded - leftCows - 1;
        if(rightCows > 2 * leftCows || leftCows > 2 * rightCows){
            ans ++;
        }
    }
    cout << ans;

}
