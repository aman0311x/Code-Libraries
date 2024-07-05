//https://www.spoj.com/problems/BUGLIFE/
#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>>adj;
vector<int>gender;
bool suspicious;
void dfs(int t, int c) {
    if(suspicious) return;
    gender[t] = c;
    for(auto child: adj[t]){
        if(gender[child] == -1){
            dfs(child, 1 - c);
        }
        else if(gender[t]==gender[child]){
            suspicious = true;
            return;
        }
    }
}
void solve() {
    cin >> n >> m;
    suspicious = false;
    adj.clear();
    adj.resize(n + 1);
    gender.assign(n + 1, -1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(gender[i] == -1){
            dfs(i, 0);
        }
    }
   cout << (!suspicious?"No suspicious bugs found!":"Suspicious bugs found!") << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t, tc = 0; cin >> t;
    while(t--){
            cout << "Scenario #" << ++tc << ":\n";
        solve();
    }
    return 0;
}
