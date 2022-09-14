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
const int oo = 1e18, K = 30;

struct elem{
	int t[3], i;
};

void print(elem x){
	cerr << x.t[0] << " " << x.t[1] << " " << x.t[2] << "   ";
}

void solve(){
	int n; cin >> n;
	vector<elem>tab;
	for (int i = 0; i<n; i++){
		elem x; cin >> x.t[0] >> x.t[1] >> x.t[2];
		x.i = i;
		tab.emplace_back(x);
	}
	vector<bool>vis(n, 0);
	vector<elem>a[3];
	for (int i = 0; i<3; i++) {
		a[i] = tab;
		sort(a[i].begin(), a[i].end(), [&](auto a, auto b){return (a.t[i] == b.t[i]?a.i < b.i:a.t[i] < b.t[i]);});
	}
	
	while (1){
		for (int i = 0; i<3; i++){
			while (a[i].size() && vis[a[i].back().i]){
				a[i].pop_back();
			}
		}
		int m = min({(int)a[0].size(), (int)a[1].size(), (int)a[2].size()});
		if (!m){
			cout << "NIE\n";
			return;
		} 
		bool found = 0;
		for (int i = 0; i<3; i++){
			for (int j = i+1; j<3; j++){
				if (a[i].back().i == a[j].back().i){
					vis[a[i].back().i] = 1;
					//debug(a[i].back().i, 1);
					a[i].pop_back();
					a[j].pop_back();
					found = 1;
					break;
				}
			}
			if (found) break;
		}
		if (found) continue;
		// print(a[0].back());
		// print(a[1].back());
		// print(a[2].back());
		// cerr << "\n";
		for (int i = 0; i<3; i++){
			for (int j = 0; j<3; j++){
				if (i == j) continue;
				if (a[i].back().t[i] <= a[j].back().t[i]){
					//debug(i, j);
					vis[a[j].back().i] = 1;
					//debug(a[j].back().i, 2);
					a[j].pop_back();
					found = 1;
				}
			}
			if (found) break;
		}
		if (found) continue;
		int ans = 0;
		for (int i = 0; i<3; i++){
			int tmp = 0;
			for (int j = 0; j<3; j++){
				tmp = max(tmp, a[j].back().t[i]); 
			}
			//debug(tmp);
			ans += tmp;
		}
		cout << ans << "\n";
		return;
	}
	cout << "NIE\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
