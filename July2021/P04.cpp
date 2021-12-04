#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;

#define pb push_back

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

int n,m,k;
bool C[1001][1001];
bool vis[1001][1001];
map<array<int,2>, array<int,2>> M;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int q = 0; q < m; q++) {
            char c; cin >> c;
            C[i][q] = (c != '#');
        }
    }

    for (int i = 0; i < k; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        M[{a-1,b-1}] = {c-1,d-1};
    }

    queue<array<int, 3>> pq;
    pq.push({0, 0, 0});
    vis[0][0] = 1;

    while(pq.size()){
        auto f = pq.front();
        pq.pop();

        if(f[1] == n-1 && f[2] == m-1) {
            cout << -1*f[0];
            break;
        }

        if (M.find({f[1], f[2]}) != M.end()){
            auto a = M[{f[1], f[2]}];
            if(!vis[a[0]][a[1]]){
                pq.push({f[0], a[0], a[1]});
                vis[a[0]][a[1]] = true;
            }
        }
        else {
            for(int i=0; i<4; i++){
                if(0 <= f[1] + dx[i] < n && 0 <= f[2] + dy[i] < m && C[f[1] + dx[i]][f[2] + dy[i]] && !vis[f[1] + dx[i]][f[2] + dy[i]]){
                    pq.push({f[0]-1, f[1] + dx[i], f[2] + dy[i]});
                    vis[f[1]+dx[i]][f[2]+dy[i]] = true;
                }
            }
        }

    }
}
