#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) {
        int n, a, b; cin >> n >> a >> b;
        int x = n ^ a, y = n ^ b;
        int ans = max(x ^ b, y ^ a);
        for (int i = n+1; i > 0; i >>= 1) {
            if (x & i != y & i) {
                ans = min(ans, i);
                break;
            }
        }
        cout << ans << "\n";
    }
}
