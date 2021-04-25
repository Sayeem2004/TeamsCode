#include <bits/stdc++.h>

using namespace std;

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define pi pair<int, int>
#define mp make_pair
#define F first
#define S second
int n, m, r;
vi a;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> r;
	a.rsz(n);
	F0R(i, n) cin >> a[i];
	sort(a.begin(), a.end());
	int ans = 0;
	if (a[0]-r>0) ans++;
	if (a[n-1]+r<m) ans++;
	for (int i = 0; i < n-1; i++) {
        if (a[i]+r+1<a[i+1]-r) ans++;
	}
	cout << ans;
}
