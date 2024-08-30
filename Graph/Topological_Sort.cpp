//cses.fi/problemset/task/1679/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
vector<int>adj[N];
vector<bool>visited;
vector<int>ans;
int n, m;
void dfs(int node){
    visited[node] = true;
    for(auto a : adj[node]){
        if(!visited[a]){
            dfs(a);
        }
    }
    ans.push_back(node);
}
void toposort(){
    visited.assign(n + 1, false);
    ans.clear();

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    reverse(ans.begin(),ans.end());
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    toposort();
    vector<int>ind(n + 1);
    for(int i = 1; i <= n; i++){
        ind[ans[i - 1]] = i;
    }
    bool valid = true; // validity check
    for(int i = 1; i <= n; i++){
        for(auto j : adj[i]){
            if(ind[j] <= ind[i]){
                valid = false;
                break;
            }
        }
        if(!valid) break;
    }
    if(valid){
        for(auto a : ans){
            cout << a << " ";
        }
        cout << '\n';
    }
    else {
        cout << "IMPOSSIBLE\n";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}