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

void solve(){
	int n; cin >> n;
	map<int, vector<int>>left;
	map<int, vector<int>>right;
	vector<pair<int, int>>tab;
	for (int i = 0; i<n; i++){
		int x, y; cin >> x >> y;
		tab.emplace_back(x, y);
	}	
	string s; cin >> s;
	for (int i = 0; i<n; i++){
		if (s[i] == 'R'){
			left[tab[i].second].push_back(tab[i].first);
		} else {
			right[tab[i].second].push_back(tab[i].first);
		}
	}
	for (auto &x: left) sort(x.second.begin(), x.second.end());
	for (auto &x: right) sort(x.second.begin(), x.second.end());
	for (auto x: left){
		for (auto y: x.second){
			int it = lower_bound(right[x.first].begin(), right[x.first].end(), y)-right[x.first].begin();
			//debug(it, y);
			if (it < (int)right[x.first].size()){
				cout << "Yes\n";
				return;
			} 
		}
	}
	cout << "No\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
