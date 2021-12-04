#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<vector<int>> P(3, vector<int>(n+1));
    for (int i = 1; i <= n; i++) {
        P[0][i] = P[0][i-1] + (s[i-1] == 'A');
        P[1][i] = P[1][i-1] + (s[i-1] == 'B');
        P[2][i] = P[2][i-1] + (s[i-1] == 'C');
    }
    int ans = 0;
    for (int i = 0; i < n; i+=k) {
        int a = 0, b = 0, c = 0;
        for (int q = 0; q < k && i+q < n; q++) {
            int mx = max(P[0][i+q+1], max(P[1][i+q+1], P[2][i+q+1]));
            if (P[0][i+q+1] == mx) a++;
            if (P[1][i+q+1] == mx) b++;
            if (P[2][i+q+1] == mx) c++;
        }
        ans += max(a, max(b,c));
    }
    cout << ans+1 << "\n";
}
