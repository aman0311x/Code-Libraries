#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct MergeSortTree {
    ll n;
    vector<vector<ll>> tree;

    MergeSortTree(ll n) : n(n) {
        tree.resize(4 * n);
    }

    void build(const vector<ll>& ar, ll node, ll l, ll r) {
        if (l == r) {
            tree[node].push_back(ar[l]);
            return;
        }
        ll mid = (l + r) / 2;
        build(ar, node * 2 + 1, l, mid);
        build(ar, node * 2 + 2, mid + 1, r);

        merge(tree[node * 2 + 1].begin(), tree[node * 2 + 1].end(),
              tree[node * 2 + 2].begin(), tree[node * 2 + 2].end(),
              back_inserter(tree[node]));
    }

    ll query(ll node, ll start, ll end, ll l, ll r, ll x) {
        if (l > end or r < start) {
            return 0;
        }
        if (l <= start and end <= r) {
            ll cnt = lower_bound(tree[node].begin(), tree[node].end(), x) - tree[node].begin();
            return cnt;
        }
        ll mid = (start + end) / 2;
        ll m = query(node * 2 + 1, start, mid, l, r, x);
        ll n = query(node * 2 + 2, mid + 1, end, l, r, x);
        return m + n;
    }

    void build(const vector<ll>& ar) {
        build(ar, 0, 0, n - 1);
    }

    ll query(ll l, ll r, ll x) {
        return query(0, 0, n - 1, l, r, x);
    }
};

void solve() {
    ll n;
    cin >> n;
    
    
    vector<ll> ar(n); 
    for (ll i = 0; i < n; i++) {
        cin >> ar[i];
    }

    MergeSortTree segTree(n);
    segTree.build(ar);

    
    ll q;
    cin >> q;
    
    while (q--) {
        ll i;
        cin >> i;
        --i; 

        ll l = 0, r = n - 1;
        ll less_xl, greater_xl, less_xr, greater_xr, ans;

        less_xl = segTree.query(l, i, ar[i]);
        greater_xl = (i - l + 1) - segTree.query(l, i, ar[i] + 1);
        less_xr = segTree.query(i, r, ar[i]);
        greater_xr = (r - i + 1) - segTree.query(i, r, ar[i] + 1);

        ans = less_xl * greater_xr + greater_xl * less_xr;
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
