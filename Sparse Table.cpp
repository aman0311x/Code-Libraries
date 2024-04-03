#include<bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    int ar[n];
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    int k = log2(n); // number of rows
    int dp[k + 1][n + 1];
    for(int i = 0; i < n; i++){
        dp[0][i] = ar[i]; // base case
    }

    for(int j = 1; j <= k; j++){
        for(int i = 0; i + (1 << j) <= n; i++){
            dp[j][i] = min(dp[j - 1][i], dp[j - 1][i + (1 << j - 1)]);
        }
    }
    int q; cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;

        int i = log2(b - a + 1);
        int ans = min(dp[i][a], dp[i][b - (1 << i) + 1]);

        cout << ans << '\n';
    }


}
