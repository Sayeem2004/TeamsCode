#include <bits/stdc++.h>
using namespace std;
#define ll int64_t


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, q; cin >> n >> m >> q;
    vector<int> R(n);
    map<pair<int, int>, int> O2, O3;
    vector<set<int>> A(n)
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        A[a-1].insert(b-1);
        A[b-1].insert(a-1);
    }
}
