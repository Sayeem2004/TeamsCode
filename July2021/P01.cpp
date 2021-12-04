#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    set<int> S;
    S.insert(0);
    S.insert(n);
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        int a; cin >> a;
        if (c == 'R') S.insert(a);
        else {
            auto itr = S.lower_bound(a);
            int b = *itr;
            itr--;
            int c = *itr;
            cout << b-c << "\n";
        }
    }
}
