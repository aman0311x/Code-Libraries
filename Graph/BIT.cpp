// https://www.spoj.com/problems/UPDATEIT/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define llu unsigned long long

const int N = 10005;
int n,u,i,l,r,val,q;
llu tree[N];

void update(int ind, ll val){
    for(; ind <= n; ind += (ind & -ind)){
        tree[ind] += val;
    }
}
llu query(int ind) {
    llu sum = 0;
    for(; ind > 0; ind -= (ind & -ind)){
        sum += tree[ind];
    }
    return sum;
}
void range_update (int i, int j, ll val)
{
    update (i,val);
    update (j+1,-val);
}
void solve() {

    cin >> n >> u;
    memset(tree, 0, sizeof(llu) * (n + 1));

    while(u--){
        cin >> l >> r >> val;
        range_update(l + 1, r + 1, val);
    }
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        cout<< query(n + 1) << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
