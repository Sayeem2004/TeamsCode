#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define pb push_back

int n, m;
map<pii, vector<pii>> g;
set<pii> connected;
map<pii, int> cmp;
map<int,int> cmpsz;
int curr = 0;

void dfs(pair<int,int> p){
	if(cmp[p]) return;
	cmp[p] = curr;
	cmpsz[curr]++;
	for(auto a: g[p]){
		dfs(a);
	}
}

int main(){
    cin >> n >> m;
    while(m--){
    	int a,b,c,d; cin >> a >> b >> c >> d;
    	g[make_pair(a,b)].pb(make_pair(c,d));
    	g[make_pair(c,d)].pb(make_pair(a,b));
    	connected.insert(make_pair(a,b));
    	connected.insert(make_pair(c,d));
	}

	int ret = 0;
	for(auto p=connected.begin(); p!=connected.end(); p++){
		++curr;
		dfs(*p);
		ret += cmpsz[cmp[*p]];
	}

	cout << ret + n*n-connected.size();
}
