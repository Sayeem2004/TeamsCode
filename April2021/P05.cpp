#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n,vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int q = 0; q < m; q++) {
            cin >> v[i][q];
        }
    }
    vector<vector<int>> ans(n,vector<int>(m,0));
    for (int i = 0; i < n; i++) {
        for (int q = 0; q < m; q++) {
            if (v[i][q] == 1) continue;
            if (i == 0 && q == 0) {
                ans[i][q] = 1;
                continue;
            }
            if (i == 0) ans[i][q] = ans[i][q-1];
            else if (q == 0) ans[i][q] = ans[i-1][q];
            else ans[i][q] = ans[i-1][q] + ans[i][q-1];
            ans[i][q] %= 1000000007;
        }
    }
    cout << ans[n-1][m-1] << "\n";
}
