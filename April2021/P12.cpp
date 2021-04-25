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
const int MOD = 1000000007;
int n, k, l;
vector<vi> p;
vector<vector<ll>> dp;
string s;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k >> l;
	p.rsz(n+1, vi(n+1, 0));
	F0R(i, n) {
        cin >> s;
        F0R(j, n) {
            if (s[j]=='S') p[i][j]=1;
        }
	}
	R0F(i, n) R0F(j, n) p[i][j] += p[i+1][j];
	R0F(i, n) R0F(j, n) p[i][j] += p[i][j+1];

	dp.rsz(n, vector<ll>(n, 0));
	F0R(i, n) F0R(j, n) if (p[i][j]>=l) dp[i][j]=1;
	F0R(step, k) {
        F0R(i, n) F0R(j, n) {
            dp[i][j]=0;
            FOR(k, i+1, n) if (p[i][j]-p[k][j]>=l) dp[i][j]=(dp[i][j]+dp[k][j])%MOD;
            FOR(k, j+1, n) if (p[i][j]-p[i][k]>=l) dp[i][j]=(dp[i][j]+dp[i][k])%MOD;
        }
	}
	cout << dp[0][0] << '\n';
}
