//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
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
	vector<pair<int, int>>p(n);
	for (int i = 0; i<n; i++) cin >> p[i].first >> p[i].second;
	set<pair<int, int>>s;
	for (auto x: p) s.insert(x);
	vector<int>X = {-1, 1, 0, 0};
	vector<int>Y = {0, 0, -1, 1};
	queue<pair<int, int>>q;
	map<pair<int, int>, int>dist;
	map<pair<int, int>, pair<int, int>> from;
	for (int i = 0; i<n; i++){
		for (int k = 0; k<4; k++){
			pair<int, int>v = {p[i].first+X[k], p[i].second+Y[k]};
			if (s.find(v) == s.end()){
				if (dist.find(p[i]) == dist.end()){
					dist[p[i]] = 1;
					from[p[i]] = v;
					q.push(p[i]);
				}
			}
		}
	}

	while (q.size()){
		pair<int, int>v = q.front();q.pop();
		for (int k = 0; k<4; k++){
			pair<int, int>x = {v.first+X[k], v.second+Y[k]};
			if (s.find(x) != s.end()){
				if (dist.find(x) == dist.end()){
					dist[x] = dist[v] + 1;
					from[x] = from[v];
					q.push(x);
				}
			}
		}
	}

	for (auto x: p){
		cout << from[x].first << " " << from[x].second << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}