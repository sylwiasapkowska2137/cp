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
const int oo = 1e18, oo2 = 1e9 + 7, K = 30;
const int mod = 998244353;
int n = 9;

void solve(){
	vector<pair<int, int>>pones;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			char c; cin >> c;
			if (c == '#') pones.emplace_back(i, j);
		}
	}
	auto N = pones.size();
	int ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			for (int k = j + 1; k < N; k++)
				for (int l = k + 1; l < N; l++){
					auto x1 = pones[i].first - pones[j].first;
					auto y1 = pones[i].second - pones[j].second;
					auto x2 = pones[i].first - pones[k].first;
					auto y2 = pones[i].second - pones[k].second;
					if (x1 * x1 + y1 * y1 == x2 * x2 + y2 * y2 && x1 * x2 + y1 * y2 == 0 && pones[l].first == pones[i].first - x1 - x2 && pones[l].second == pones[i].second - y1 - y2)
						ans++;
				}
	cout << ans << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}
