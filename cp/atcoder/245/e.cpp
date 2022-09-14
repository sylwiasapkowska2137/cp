//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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

struct elem{
	int a, b, i;
	elem(int _a = 0, int _b = 0, int _i = 0){
		a = _a, b = _b, i = _i;
	}
};

void solve(){
	int n, m; cin >> n >> m;
	vector<int>a(n), b(n), c(m), d(m);
	for (int i = 0; i<n; i++) cin >> a[i];
	for (int i = 0; i<n; i++) cin >> b[i];
	for (int i = 0; i<m; i++) cin >> c[i];
	for (int i = 0; i<m; i++) cin >> d[i];
	vector<elem>tab;
	for (int i = 0; i<n; i++){
		tab.emplace_back(a[i], b[i], 0);
	}
	for (int i = 0; i<m; i++){
		tab.emplace_back(c[i], d[i], 1);
	}
	sort(tab.begin(), tab.end(), [](auto a, auto b){
		if (a.a == b.a){
			if (a.b == b.b){
				return a.i > b.i;
			}
			return a.b > b.b;
		}
		return a.a > b.a;
	});
	multiset<int>s;
	for (auto [a, b, i]: tab){
		//debug(a, b, i);
		if (i){ //pudelko
			s.insert(b);
		} else {
			auto it = s.lower_bound(b);
			if (it == s.end()){
				cout << "No\n";
				return;
			}
			s.erase(it);
		}
	}
	cout << "Yes\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
