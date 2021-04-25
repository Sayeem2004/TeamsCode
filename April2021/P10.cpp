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
int n, m, c;
map<string, vector<pair<string, int>>> adj;
string base, a, b;
map<string, int> tobase;

void dfs(string i) {
    for (auto p : adj[i]) {
        if (tobase.find(p.F)==tobase.end()) {
            tobase[p.F]=tobase[i]+p.S;
            dfs(p.F);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	F0R(i, n-1) {
	    cin >> a >> b >> c;
	    if (i==0) base=a;
	    adj[a].pb(mp(b, c));
	    adj[b].pb(mp(a, -c));
	}
	tobase[base]=0;
	dfs(base);
	F0R(i, m) {
	    cin >> a >> b;
	    cout << tobase[b]-tobase[a] << '\n';
	}
	return 0;
}
