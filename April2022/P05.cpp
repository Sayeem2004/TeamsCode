// Solved by Yuval
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
typedef tree <pair<ll,ll>,null_type,less<pair<ll,ll>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main() {
    ll N, R, M, K; cin >> N >> R >> M >> K;
    vector<ll> ppl(N);
    for(ll & i : ppl) cin >> i;
    ordered_set set;
    for(ll i = N-K; i < N; i++) set.insert({ppl[i],i});
    for(ll i = 1; i <= K; i++) set.insert({ppl[i],i});
    for(ll i = 0; i < R; i++) {
        ll src, dst, val, bet; cin >> src >> dst >> val >> bet;
        if(src <= K+1 || src+K > N) {
            set.erase({ppl[src-1],src-1});
            set.insert({ppl[dst-1],src-1});
        }
        if(dst <= K+1 || dst+K > N) {
            set.erase({ppl[dst-1],dst-1});
            set.insert({ppl[src-1],dst-1});
        }
        swap(ppl[src-1],ppl[dst-1]);
        if(set.order_of_key({val,1e18})<=K) M += bet;
        else M -= bet;
        if(M < 0) {
            cout << "BANKRUPT " << i+1 << endl;
            return 0;
        }
    }
    cout << M;
}
