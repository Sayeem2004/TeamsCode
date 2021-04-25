#include <bits/stdc++.h>

#define MAXN 100001
int arr[MAXN];

using namespace std;


int main (void)
{
    ios_base::sync_with_stdio (0); cin.tie (nullptr); cout.tie (nullptr);

    string s; int n; cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++)
        s[i] = s[i-arr[i]];
    cout << s << '\n';

    return 0;
}
