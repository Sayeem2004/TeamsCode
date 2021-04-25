#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define pb push_back;

int n;
const int target = 20210424;

int main(){
    cin >> n;
    while(n--){
        int m; cin >> m;
        int diff = target - m;
        if(diff%124==1 || diff%124==123) cout << "Yes\n";
        else cout << "No\n";
    }
}
