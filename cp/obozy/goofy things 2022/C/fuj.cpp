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

const long long INF = 1e18+7;

bool check(vector<pair<int, int>>&points, int n, long long mid){
	queue<pair<int, int>>q;
	long long mini = INF, maxi = -INF;
	for (auto [x, y]:points){
		while (!q.empty() && q.front().first <= (LL)x-mid){
			mini = min(mini, (LL)q.front().second);
			maxi = max(maxi, (LL)q.front().second);
			q.pop();	
		}
		if (maxi >= y+mid || mini <= y-mid) return 1;
		q.push({x, y});
	}
	return 0;
}

void solve(){
	int n; cin >> n;
	vector<pair<int, int>>points;
	for (int i = 0; i<n; i++){
		int x, y; cin >> x >> y;
		points.emplace_back(x, y);
	}
	sort(points.begin(), points.end());
	long long L = 1, R = (1LL<<32)-1, ans = 0;
	while (R>=L){
		long long m = (L+R)/2;
		if (check(points, n, m)) {
			ans = m;
			L = m+1;
		} else R = m-1;
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
