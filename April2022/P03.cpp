// Solved by Mohammad Khan & Mark Ma
#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int m, n; cin >> m >> n;
    char grid[m+1][n+1];
    vector<pair<int, int>> A, B;
    for (int i = 0; i <= m; i++) {
        for (int q = 0; q <= n; q++) {
            cin >> grid[i][q];
            if (grid[i][q] == 'A') A.push_back({i, q});
            if (grid[i][q] == 'B') B.push_back({i, q});
        }
    }
    int ans = 0;
    for (int i = 0; i < A.size(); i++) {
        for (int q = 0; q < B.size(); q++) {
            int dx = (B[q].first - A[i].first) / (__gcd(abs(B[q].first-A[i].first), abs(B[q].second-A[i].second)));
            int dy = (B[q].second - A[i].second) / (__gcd(abs(B[q].first-A[i].first), abs(B[q].second-A[i].second)));
            bool br = true;
            for (int x = A[i].first, y = A[i].second; x != B[q].first || y != B[q].second; x += dx, y += dy) {
                if (grid[x][y] == 'C') {
                    br = false; break;
                }
            }
            if (br) {
                ans += 1;
            }
        }
    }
    cout << ans << "\n";
}
