// Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;

void __print(int x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
	cerr << '{';
	__print(x.first);
	cerr << ", ";
	__print(x.second);
	cerr << '}';
}
template <typename T>
void __print(const T &x)
{
	int f = 0;
	cerr << '{';
	for (auto &i : x)
		cerr << (f++ ? ", " : ""), __print(i);
	cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
	__print(t);
	if (sizeof...(v))
		cerr << ", ";
	_print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
	cerr << "[" << #x << "] = ["; \
	_print(x)
#else
#define debug(x...)
#endif

#define int long long
const int oo = 1e18, oo2 = 1e9 + 7, K = 21;
// #warning change K to 21
const int mod = 998244353;

void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> g(n + 1);
	vector<int> used(n + 1);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	string s;
	cin >> s;
	s = "$" + s;
	vector<int> sz(n + 1), ans(n + 1), cnt((1 << K) + 5);
	function<int(int, int)> dfs = [&](int v, int pa)
	{
		sz[v] = 1;
		for (auto x : g[v])
		{
			if (x == pa || used[x])
				continue;
			sz[v] += dfs(x, v);
		}
		return sz[v];
	};
	function<int(int, int, int)> get = [&](int v, int ms, int pa)
	{
		for (auto x : g[v])
		{
			if (x == pa || used[x])
				continue;
			if (sz[x] * 2 > ms)
				return get(x, ms, v);
		}
		return v;
	};
	auto ti = [&](char c)
	{ return (int)(c - 'a'); };
	function<void(int, int, int, int)> dfs2 = [&](int v, int pa, int xx, int d)
	{
		d ^= (1 << ti(s[v]));
		cnt[d] += xx;
		for (auto x : g[v])
		{
			if (x == pa || used[x])
				continue;
			dfs2(x, v, xx, d);
		}
	};
	function<int(int, int, int)> calc = [&](int v, int pa, int d)
	{
		d ^= (1 << ti(s[v]));
		int res = cnt[d];
		for (int i = 0; i < K; i++)
			res += cnt[d ^ (1 << i)];
		for (auto x : g[v])
		{
			if (x == pa || used[x])
				continue;
			res += calc(x, v, d);
		}
		ans[v] += res;
		return res;
	};
	function<void(int)> centroid = [&](int v)
	{
		v = get(v, dfs(v, v), v);
		dfs2(v, v, 1, 0);
		int res = cnt[0];
		for (int i = 0; i < K; i++)
			res += cnt[(1 << i)];
		for (auto x : g[v])
		{
			if (used[x])
				continue;
			dfs2(x, v, -1, (1 << ti(s[v])));
			res += calc(x, v, 0);
			dfs2(x, v, 1, (1 << ti(s[v]))); // undo changes
		}
		ans[v] += res / 2;
		dfs2(v, v, -1, 0); // clear cnt

		// debug(v, ans);

		used[v] = 1;
		for (auto x : g[v])
		{
			if (!used[x])
			{
				centroid(x);
			}
		}
	};
	centroid(1);
	for (int i = 1; i <= n; i++)
		cout << ans[i] + 1 << " ";
	cout << "\n";
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}
