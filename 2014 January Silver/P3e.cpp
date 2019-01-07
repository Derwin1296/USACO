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
struct interval{
  int sTime;
  int eTime;
  interval(int a, int b){
      sTime = a;
      eTime = b;
  }
  bool operator<(const interval& d){
    if(d.eTime != eTime){
        return eTime < d.eTime;
    }
    else{
        return sTime < d.sTime;
    }
  }
  void setStart(int c){
      sTime = c;
  }
  void setEnd(int c){
      eTime = c;
  }
};
vector<interval> orderedInt;
// Find # of max programs
int solve(){
    int progUsed = 2;
    interval first = orderedInt[0];
    interval second = orderedInt[1];
    int pointer = 2;
    while(pointer < orderedInt.size()){
        interval toProcess = orderedInt[pointer];
        // Usable by first, but not second
        if(toProcess.sTime >= first.eTime && toProcess.sTime < second.eTime){
            first.setEnd(toProcess.eTime);
            progUsed ++;
        }
        // Usable by second, not usable by first
        else if(toProcess.sTime >= second.eTime && toProcess.sTime < first.eTime){
            second.setEnd(toProcess.eTime);
            progUsed ++;
        }
        // Usable by both
        else if(toProcess.sTime >= second.eTime && toProcess.sTime >= first.eTime){
            progUsed ++;
            // Choose one with higher end time
            if(second.eTime >= first.eTime){
                second.setEnd(toProcess.eTime);
            }
            else{
                first.setEnd(toProcess.eTime);
            }
        }
        pointer++;
    }
    return progUsed;
}
int main() {
    freopen("recording.in", "r", stdin);
    freopen("recording.out", "w", stdout);
    int n; cin >> n;
    F0R(i, n){
        int a, b;
        cin >> a >> b;
        orderedInt.pb(interval(a, b));
    }
    sort(orderedInt.begin(), orderedInt.end());
    int ans = solve();
    cout << ans;
    // for(int i = 0; i < orderedInt.size(); i++){
    //     interval a = orderedInt[i];
    //     cout << a.eTime << ", " << a.sTime << "\n";
    // }
}
