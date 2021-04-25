#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MAXN 100001
#define int long long
int arr[MAXN];
vector<int> adj[MAXN];
set<int> reqs[MAXN];
int par[MAXN];

priority_queue<pair<int,int>> q;

int ans, N;

int read (pair<int,int> s);
void new_pos (pair<int,int> s);

signed main (void)
{
    //io
    //ios_base::sync_with_stdio (0); cin.tie (nullptr); cout.tie (nullptr);

    scanf ("%lld", &N);
    for (int i = 1; i <= N; i++)
        scanf ("%lld", &arr[i]);

    int a,b;
    while (scanf ("%lld %lld", &a, &b) != EOF)
    {
        adj[a].push_back (b);
        reqs[a].insert (b);
        par[b] = a;
    }

    //get leafs in form {interest value, page #}
    vector<pair<int,int>> leaves;
    for (int i = 1; i <= N; i++)
        if (adj[i].size () == 0)
            leaves.push_back ({arr[i],i});

    //debug
    //cerr << "here" << endl;
    //for (auto i = leaves.begin(); i != leaves.end(); i++)
    //    cerr << (*i).F << " " << (*i).S << endl;

    //main priority queue thing
    for (auto i = leaves.begin(); i != leaves.end(); i++)
        q.push (*i);

    while (q.size ())
    {
        pair<int,int> s = q.top(); q.pop();

        //debug
        //cerr << "q size " << q.size () << " ans " << ans << endl;
        //cerr << "stuck thing " << s.F << " " << s.S << endl;

        ans += read (s);

        new_pos (s);
    }

    cout << ans << '\n';

    return 0;
}

vector<int> bit (MAXN, 0);
int sum (int k)
{
    int s = 0;
    for (k++; k > 0; k -= k&-k) s += bit[k];
    return s;
}

void add (int k, int x)
{
    for (k++; k <= N+1; k += k&-k) bit[k] += x;
}

int read (pair<int,int> s)
{
    add (s.S, s.F);
    //cerr << "sum: " << sum (s.S) << endl;
    return sum (s.S) + s.F + s.F;
}

void new_pos (pair<int,int> s)
{
    if (par[s.S] == 0) return;
    reqs[par[s.S]].erase (s.S);
    if (!reqs[par[s.S]].size())
        q.push ({arr[par[s.S]],par[s.S]});
}
