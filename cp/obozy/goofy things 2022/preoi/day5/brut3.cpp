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

typedef long double LD;

const LL INF = 1e18;

struct line{
	LL a, b, idx; 
	line(){}
	line (LL _a, LL _b, int _idx){
		a = _a, b = _b, idx = _idx;
	}
	LL f(LL x){
		return a*x+b;
	}
	LL inter(line l){
		if (a == l.a) return INF;
		LD x = (LD)(((LD)(b-l.b))/((LD)(l.a-a)));
		//debug(x);
		return floor(x);
	}
};

void solve(){
	int n, k; cin >> n >> k;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) {
		cin >> a[i];
	}
	vector<LL>pref(n+1, 0LL);
	for (int i = 1; i<=n; i++) pref[i] = pref[i-1]+a[i];
	vector<vector<LL>>dp(n+1, vector<LL>(k+1, 0));
	vector<vector<int>>idx(n+1, vector<int>(k+1, 0));
	for (int i = 1; i<=n; i++) dp[i][1] = pref[i]*(pref[n]-pref[i]);
	for (int ile = 2; ile<=k; ile++){
		deque<line>dq;
		dq.push_back({0, 0, 0});
		for (int i = 1; i<=n; i++){
			
			LL val = pref[n]-pref[i];
			while (dq.size() >= 2 && dq.back().f(val) <= dq[dq.size()-2].f(val)) dq.pop_back();
			dp[i][ile] = dq.back().f(val) + pref[i]*val;
			idx[i][ile] = dq.back().idx;
			//cerr << "ask for max in x=" << val << ", ans: " << dq.back().f(val) << "\n";
			line curr = line{-pref[i], dp[i][ile-1], i};
			//cerr << "add a: " << -pref[i] << " b: " << dp[i][ile-1] << "\n";
			while (dq.size() >= 2 && curr.inter(dq.front()) >= dq.front().inter(dq[1])) dq.pop_front();
			dq.push_front(curr);
		}
		//cerr << "\n";
	}
	/*
	for (int i = 1; i<=k; i++){
		for (int j = 1; j<=n; j++){
			cerr << idx[j][i] << " ";
		}
		cerr << "\n";
	}
	*/
	LL ans = -1;
	int last = -1;
	for (int i = 1; i<=n; i++){
		if (ans < dp[i][k]){
			ans = dp[i][k];
			last = i;
		}
	}
	cout << ans << "\n";
	return;
	//debug(last);
	vector<int>tab;
	const int INF2 = 1e9+7;
	while (1){
		tab.push_back(last);
		if (last == 0) {
			tab.pop_back();
			tab.push_back(INF2);
		}
		last = idx[last][k];
		k--;
		if (!k) break;
	}
	sort(tab.begin(), tab.end());
	if (tab[0] == INF) tab[0] = 1;
	for (int i = 1; i<(int)tab.size(); i++){
		if (tab[i] <= tab[i-1] || tab[i] == INF2) tab[i] = tab[i-1]+1;
	}
	for (auto x: tab) cout << x << " ";
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
