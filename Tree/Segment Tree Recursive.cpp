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
#include <iostream>

using namespace std;

ll a[MX];
int seg_tree[4 * MX];

int construct(int index, int left_interval, int right_interval){
    if(left_interval == right_interval){
        seg_tree[index] = a[left_interval];
    }
    else{
        int left = construct(2 * index + 1, left_interval, (left_interval + right_interval) / 2);
        int right = construct(2 * index + 2, (left_interval + right_interval) / 2 + 1, right_interval);
        seg_tree[index] = left + right;
    }
    return seg_tree[index];
}

int update(int node, int ll, int rl, int q, int val){
    // 
    if (rl < q || ll > q) return seg_tree[node];
    if (q == ll && q == rl) seg_tree[node] = val;
    else {
        int left = update(2*node+1, ll, (ll+rl)/2, q, val);
        int right = update(2*node+2, (ll+rl)/2 + 1, rl, q, val);
        st[node] = left + right;
    }
    return st[node];
}

int query(int index, int l_l, int l_r, int q_l, int q_r){
    // Total overlap, return node value
    if(q_l <= l_l && q_r >= l_r){
        return seg_tree[index];
    }
    // Out of range: return dummy value
    else if(q_l > l_r || q_r < l_l){
        return 0;
    }
    // Partial overlap, return combination of both children
    else{
        int left = query(2 * index + 1, l_l, (l_l + l_r) / 2, q_l, q_r);
        int right = query(2 * index + 2, (l_l + l_r) / 2 + 1, l_r, q_l, q_r);
        return left + right;
    }
}

int main()
{
}
