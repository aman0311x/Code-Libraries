/*https://www.spoj.com/problems/HORRIBLE/ */

#include<bits/stdc++.h>
using namespace std;
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef unsigned long long ull;

const int   N = 100005;
ll n, q, bit1[N],bit2[N];

void update(ll bit[], int x, ll val) {
	for (x; x<=N; x+=x&(-x)) {
        bit[x] += val;
	}
}

ll get(ll bit[],int x) {
	ll ans = 0;
	for (x; x>0; x-=x&(-x)) ans += bit[x];
	return ans;
}
ll prefix_query(int indx){
    return get(bit1,indx) * indx - get(bit2,indx);
}
void solve() {
    cin >> n >> q;
    memset(bit1, 0, sizeof bit1);
    memset(bit2, 0, sizeof bit2);
    while(q--){
        int t;
        cin >> t;
        if(t == 0){
            ll p, q, v;
            cin >> p >> q >> v;
            update(bit1,p, v);
            update(bit1,q + 1, -v);
            update(bit2, p, v * (p - 1));
            update(bit2, q + 1, -v*q);

        }

        else if(t == 1){
            int p, q;
            ll ans = 0;
            cin >> p >> q;
            ans = prefix_query(q) - prefix_query(p - 1);
            cout << ans << '\n';
        }
    }
}

int main() {
    FASTER
    int t = 1, tc = 0; cin  >> t;
    while(t--){
        //cout << "Case " << ++tc << ": ";
        solve();
    }
}
