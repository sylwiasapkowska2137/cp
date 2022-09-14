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
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)



void solve(){
	int n; cin >> n;
	vector<int>pre(n), in(n);
	for (int i = 0; i<n; i++) cin >> pre[i];
	for (int i = 0; i<n; i++) cin >> in[i];
	vector<int>p1(n+1), p2(n+1);
	for (int i = 0; i<n; i++) p1[pre[i]] = i;
	for (int i = 0; i<n; i++) p2[in[i]] = i;
	vector<vector<int>>G(n+1);
	
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
