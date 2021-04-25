#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define pb push_back;

int n;

int main(){
    cin >> n;
    int arr[n], s[n];
    map<int,int> rank;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        s[i] = arr[i];
    }
    sort(s, s+n, greater<int>());
    for(int i=0; i<n; i++){
        if(i>0 && s[i] == s[i-1]) rank[s[i]] = rank[s[i-1]];
        else rank[s[i]] = i+1;
    }
    for(int i: arr) cout << rank[i] << ' ';
}
