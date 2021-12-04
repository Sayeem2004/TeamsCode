#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;

#define pb push_back

void solve(){
    int k,n; cin >> k >> n;

    if(k==1){
        cout << "-1 -1\n";
        return;
    }
    if(k%2){
        printf("%d %d\n", k/2, k/2 + 2);
        return;
    }

    int sp = 0, lp = 0;
    for(int i=2; i<=sqrt(k); i++){
        if(i % 2 == 1 && k%i == 0 && !sp){
            sp=i;
        }
        if(i%2 == 0 && k%i == 0 && (k/i)%2 == 1 && !lp){
            lp=k/i;
        }
    }
    ///printf("%d %d \n", sp, lp);
    int left = 0, right = 0;
    if(sp){
        int m = k/sp;
        int l = m - sp/2, r = m+sp/2;
        if(l >= 0 && r < k){
            left = l;
            right = r;
        }
    }
    if(lp){
        int m = lp/2;
        int len = k / lp;
        int l = m - len + 1, r = m+len;
        if(l >= 0 && r < k){
            left = l;
            right = r;
        }
    }
    if(!left) left=1;
    if(!left || !right) cout << "-1 -1\n";
    else cout << left << ' ' << right+1 << '\n';
}

int main(){
    int d; cin >> d;
    while(d--) solve();
}
