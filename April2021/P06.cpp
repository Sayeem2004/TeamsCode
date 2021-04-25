#include <bits/stdc++.h>

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
int n, m, q, temp, a, b;
vi ans;
vector<vi> adj;
vpi tosort;
vector<bool> vis;
priority_queue<pair<int, int>> pq;

bool cmp(pi a, pi b) {
    if (a.F==b.F) return a.S<b.S;
    return a.F>b.F;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> q;
	ans.clear();
	ans.rsz(n, 0);
	F0R(i, m) {
	    cin >> temp;
	    cin >> ans[temp-1];
	    pq.push(mp(ans[temp-1], temp-1));
	}
	adj.rsz(n);
	F0R(i, q) {
	    cin >> a >> b;
	    a--; b--;
	    if (a==0 || b==0) continue;
	    adj[a].pb(b);
	    adj[b].pb(a);
	}
	vis.rsz(n, false);
	while (! pq.empty()) {
        auto c = pq.top();
        pq.pop();
        if (vis[c.S]) continue;
        ans[c.S]=max(ans[c.S], c.F);
        vis[c.S]=true;
        for (auto nb : adj[c.S]) {
            if (vis[nb]) continue;
            if (ans[c.S]/2 > ans[nb]) {
                ans[nb]=ans[c.S]/2;
                pq.push(mp(ans[c.S]/2, nb));
            }
        }
	}
	F0R(i, n-1) {
	    tosort.pb(mp(ans[i+1], i+2));
	}
    sort(tosort.begin(), tosort.end(), cmp);
    F0R(i, n-1) {
        cout << tosort[i].S << ' ' << tosort[i].F << '\n';
    }
    return 0;
}
