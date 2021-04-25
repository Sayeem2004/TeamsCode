#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define pb push_back

int n;
vector<pii> arr; // 1 if begin, -1 if end

bool cmp(pii a, pii b){
	if(a.first == b.first){
		return a.second > b.second;
	}
	return a.first < b.first;
}

int main(){
    cin >> n;
    int mx = 0, curr=0;
    for(int i=0; i<n; i++){
    	int s,e; cin >> s >> e;
    	arr.pb(make_pair(s,1));
    	arr.pb(make_pair(e,-1));
	}
	sort(arr.begin(), arr.end(), cmp);
	for(auto p : arr){
		curr += p.second;
		mx = max(mx, curr);
	}
	cout << mx;
}
