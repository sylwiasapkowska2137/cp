//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
const int oo = 1e18, oo2 = 1e9+7, K = 20;
const int mod = 998244353;

void rec(vector<int>a, vector<int>b, int bit){
	assert(a.size() == b.size());
	int n = (int)a.size();
	if (bit < 0){
		for (int i = 0; i<n; i++){
			cout << a[i] << " " << b[i] << "\n";
		}
		return;
	}
	vector<vector<int>>A(2), B(2);
	for (auto v: a)	A[(bool)(v&(1<<bit))].emplace_back(v);
	for (auto v: b)	B[(bool)(v&(1<<bit))].emplace_back(v);
	// debug(A, B);
	int diff = A[0].size()-B[0].size();
	assert(diff >= 0);
	rotate(A[0].begin(), A[0].begin()+diff, A[0].end());
	vector<int>mv;
	for (int i = 0; i<diff; i++){
		mv.emplace_back(A[0].back());
		A[0].pop_back();
	}
	reverse(mv.begin(), mv.end());
	for (auto x: A[1]) mv.emplace_back(x);
	A[1] = mv;
	// debug(A, B);
	rec(A[0], B[0], bit-1);
	rec(A[1], B[1], bit-1);
}

void solve(){
	int n, m; cin >> n >> m;
	vector<int>a, b;
	for (int i = 0; i<n; i++){
		a.emplace_back(i);
		b.emplace_back(m+i);
	}
	rec(a, b, K);
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
