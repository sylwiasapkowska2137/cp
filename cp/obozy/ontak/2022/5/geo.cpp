//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
typedef long double LD;
typedef vector<pair<int, int>> T;

LD d(pair<int, int>a, pair<int, int>b){
	LD x = a.first-b.first;
	LD y = a.second-b.second;
	return sqrt(x*x+y*y);
}

LD brut(T&a){
	LD ans = oo;
	for (int i = 0; i<(int)a.size(); i++){
		for (int j = i+1; j<(int)a.size(); j++){
			ans = min(ans, d(a[i], a[j]));
		}
	}
	return ans;
}

LD rec(T px, T py){
	int n = (int)px.size();
	if (n <= 3) return brut(px); 
	int m = n/2;
	pair<int, int>midpoint = px[m];
	T A, B, C, D;
	for (int i = 0; i<n; i++){
		if (C.size() < m) C.emplace_back(px[i]);
		else D.emplace_back(px[i]);
	}
	for (int i = 0; i<n; i++){
		if (py[i].first < midpoint.first || (py[i].first == midpoint.first && py[i].second < midpoint.second && A.size() < m)) A.emplace_back(py[i]);
		else B.emplace_back(py[i]);
	}
	LD curr = min(rec(C, A), rec(D, B));
	// debug(curr, A, B, m);
	T s;
	for (int i = 0; i<n; i++){
		if (abs(py[i].first - midpoint.first) < curr) {
			s.emplace_back(py[i]);
		}
	}
	int sz = (int)s.size();
	LD ans = curr;
	for (int i = 0; i<sz; i++){
		for (int j = i+1; j<sz && abs(s[j].second - s[i].second) < ans; j++){
			ans = min(ans, d(s[i], s[j]));
		}
	}
	return ans;
}

const int MAX = 2e9;
vector<int>mm = {-MAX-1, -MAX, -MAX+1, -1, 0, 1, MAX-1, MAX, MAX+1};

void solve(){
	cerr << fixed << setprecision(5);
	int n, m; cin >> n >> m;
	T a(n), b(m);
	for (auto &[x, y]:a) cin >> x >> y;
	for (auto &[x, y]:b) cin >> x >> y;
	T ax = a, ay = a;
	sort(ax.begin(), ax.end());
	sort(ay.begin(), ay.end(), [](auto X, auto Y){
		if (X.second == Y.second) return X.first < Y.first;
		return X.second < Y.second;
	});
	LD ans = rec(ax, ay);
	map<int, vector<int>>area;
	int D = 2*ceil(ans);
	for (int i = 0; i<m; i++){
		auto [x, y] = b[i];
		area[(x/D)*MAX+(y/D)].emplace_back(i);
	}
	LD m1 = oo, m2 = oo;
	for (int i = 0; i<n; i++){
		auto [x, y] = a[i];
		int curr = (x/D)*MAX+(y/D);
		LD mini = oo;
		for (auto dd: mm){
			curr += dd;
			for (auto idx: area[curr])	mini = min(mini, d(b[idx], a[i]));
			curr -= dd;
		}
		if (mini < m1){
			m2 = m1;
			m1 = mini;
		} else if (mini < m2){
			m2 = mini;
		}
	}
	ans = min(ans, m1+m2);
	cout << fixed << setprecision(15) << ans/2.0 << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
