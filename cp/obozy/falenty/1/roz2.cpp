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

// #define int long long
const int oo = 1e9+7, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

void solve(){
	int n, k; cin >> n >> k;
	vector<int>a(n+1);
	vector<pair<int, int>>tab;
	for (int i = 1; i<=n; i++) {
		cin >> a[i];
		tab.emplace_back(a[i], i);
	}
	stable_sort(tab.begin(), tab.end());
	vector<int>L(n+1), R(n+1);
	vector<int>vis(n+1);
	for (int i = 1; i<=n; i++){
		L[i] = i-1;
		R[i] = i+1;
	}
	L[1] = -oo; R[n] = oo;
	vector<int>ret(n+1);
	int turn = 0;
	while (1){
		while (tab.size() && vis[tab.back().second]) tab.pop_back();
		if (tab.empty()) break;
		int pos = tab.back().second;
		ret[pos] = turn;
		vis[pos] = 1;
		int ck = k, curr = pos;
		while (ck > 0){
			curr = L[curr];
			if (curr == -oo) break;
			vis[curr] = 1;
			ret[curr] = turn;
			ck--;
		}
		int left = -oo, right = oo;
		if (!ck){
			curr = L[curr];
			left = curr;
		}
		ck = k, curr = pos;
		while (ck > 0){
			curr = R[curr];
			if (curr == oo) break;
			ret[curr] = turn;
			vis[curr] = 1;
			ck--;
		}
		if (!ck){
			curr = R[curr];
			right = curr;
		}
		// debug(left, right);
		if (left != -oo) R[left] = right;
		if (right != oo) L[right] = left;
		turn ^= 1;
	}
	for (int i = 1; i<=n; i++) cout << ret[i] << " ";
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
