//https://cses.fi/problemset/task/1682/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 5;
vector<int>adj[N];
vector<int>adjT[N];
int n, m;

void dfs1(int node, vector<int>&vis, stack<int>&st){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs1(it, vis, st);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<int>&vis){
    vis[node] = 1;
    for(auto it: adjT[node]){
        if(!vis[it]){
            dfs2(it, vis);
        }
    }
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adjT[v].push_back(u);
    }

    vector<int>vis(n + 1, 0);
    stack<int>st;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs1(i, vis, st);
        }
    }
    for(int i = 0; i <= n; i++) vis[i] = 0;
    vector<int>ans;
    int scc = 0;
    while(!st.empty()){
        int node = st.top();
        
        st.pop();
        if(!vis[node]){
            ans.push_back(node);
            dfs2(node, vis);
        }
    }
    if(ans.size() > 1){
        cout << "NO\n";
        cout << ans[1] << " " << ans[0] << '\n';
    }
    else {
        cout << "YES\n";
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