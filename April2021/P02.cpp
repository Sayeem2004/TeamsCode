#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

// Prime Factorization of an integer
map<int,int> pfactor(int n) {
    map<int,int> f;
    while (n % 2 == 0) {
        f[2]++;
        n /= 2;
    }
    for (int x = 3; x*x <= n; x += 2) {
        while (n%x == 0) {
            f[x]++;
            n /= x;
        }
    }
    if (n > 1) f[n]++;
    return f;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    map<int,int> mp = pfactor(n);
    vector<int> v;
    for (auto x : mp) {
        v.push_back(x.first);
    }
    sort(v.begin(),v.end());
    for (auto x : v) {
        cout << x << " " << mp[x] << "\n";
    }
}
