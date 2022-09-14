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
const int oo = 1e18, K = 30;

void solve(){
	int n; cin >> n;
	vector<vector<int>>g(n+1, vector<int>(n+1));
	for (int i = 2; i<=n; i++){
		for (int j = 1; j<i; j++){
			char c; cin >> c;
			if (c == 'R'){
				g[i][j] = g[j][i] = 1;
			}
		}
	}

	auto what = [&](int s){
		vector<int>A, B;
		for (int v = 1; v<=n; v++){
			if (v == s) continue;
			if (A.empty() || g[v][A.back()] == 1){
				A.emplace_back(v);
				continue;
			} 
			if (B.empty() || g[v][B.back()] == 0){
				B.emplace_back(v);
				continue;
			}
			if (g[A.back()][B.back()] == 1){
				A.emplace_back(B.back());
				A.emplace_back(v);
				B.pop_back();
			} else {
				B.emplace_back(A.back());
				B.emplace_back(v);
				A.pop_back();
			}
		}
		int v = s;
		if (A.empty() || g[v][A.back()] == 1){
			A.emplace_back(v);
		} else if (B.empty() || g[v][B.back()] == 0){
			B.emplace_back(v);
		} else if (g[A.back()][B.back()] == 1){
			A.emplace_back(B.back());
			A.emplace_back(v);
			B.pop_back();
		} else {
			B.emplace_back(A.back());
			B.emplace_back(v);
			A.pop_back();
		}
		if (A.size() && A.back() == s) reverse(A.begin(), A.end());
		if (B.size() && B.back() == s) {
			reverse(B.begin(), B.end());
			swap(A, B);
		}
		// debug(s, A, B);
		cout << n << "\n";
		for (auto x: A) cout << x << " ";
		for (auto x: B) cout << x << " ";
		cout << "\n";
	};

	for (int i = 1; i<=n; i++){
		what(i);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
