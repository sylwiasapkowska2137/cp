//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
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
const int oo = 1e18;

struct node{
	int syn[2] = {-1, -1};
};

struct trie{
	vector<node>tab;
	node empty;
	
	int K = 30;

	trie(){
		tab.emplace_back(empty);
	}

	void clear(){
		tab.clear();
		tab.emplace_back(empty);
	}

	void add(int x){
		int v = 0;
		for (int i = K; i>=0; i--){
			bool s = (x&(1<<i));
			if (tab[v].syn[s] == -1){
				tab[v].syn[s] = (int)tab.size();
				tab.emplace_back(empty);
			}
			v = tab[v].syn[s];
		}
	}

	int minn(int x){
		int v = 0, ans = 0;
		for (int i = K; i>=0; i--){
			bool s = (x&(1<<i));
			if (tab[v].syn[s] != -1){
				v = tab[v].syn[s];
				ans += (s?(1<<i):0);
			} else {
				v = tab[v].syn[s^1];
				ans += (s?0:(1<<i));
			}
		}
		return ans;
	}
} T;

int dnc(vector<int>a, int bit){
	if (bit < 0 || a.empty()) return 0;
	vector<int>A, B;
	for (auto x:a){
		if (x&(1<<bit)) B.emplace_back(x);
		else A.emplace_back(x);
	}
	int ans = oo;
	if (A.empty()) return dnc(B, bit-1);
	if (B.empty()) return dnc(A, bit-1);
	if ((int)A.size() < (int)B.size()) swap(A, B);
	T.clear();
	for (auto v: B) T.add(v);
	for (auto x: A) ans = min(ans, T.minn(x)^x);
	if (ans == oo) ans = 0;
	return dnc(A, bit-1)+dnc(B, bit-1)+ans;
}

void solve(){
	int n; cin >> n;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];

	int ans = dnc(a, 30);	
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; //cin >> t;
	while (t--) solve();
	
	return 0;
}
