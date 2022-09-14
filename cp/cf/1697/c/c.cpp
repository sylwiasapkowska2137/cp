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

int ti(char c){
	return (int)(c-'a');
}

struct segtree{
	vector<int>tab;
	int size = 1;

	segtree(){}

	segtree(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.assign(2*size, 0);
		for (int i = 0; i<(int)a.size(); i++) tab[i+size] = a[i];
		for (int i = size-1; i>=1; i--) tab[i] = tab[2*i]+tab[2*i+1];
	}

	void init(int n, string s, int c){
		while (size < n) size*=2;
		tab.assign(2*size, 0);
		for (int i = 0; i<(int)s.size(); i++){
			if (ti(s[i]) == c){
				tab[i+size] = 1;
			}
		}
		for (int i = size-1; i>=0; i--) tab[i] = tab[2*i]+tab[2*i+1];
	}

	void update(int x, int v){
		x += size;
		tab[x] = v;
		while (x){
			x/=2;
			tab[x] = tab[2*x]+tab[2*x+1];
		}
	}

	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = 0;
		while (r-l>1){
			if (!(l&1)) ans += tab[l+1];
			if (r&1) ans += tab[r-1];
			l/=2;r/=2;
		}
		return ans;
	}
};

void solve(){
	int n; cin >> n;
	string s, t; cin >> s >> t;
	vector<vector<int>>pos(4), pos2(4);
	for (int i = 0; i<n; i++){
		pos[ti(s[i])].emplace_back(i);
	}
	for (int i = 0; i<n; i++){
		pos2[ti(t[i])].emplace_back(i);
	}
	for (int i = 0; i<3; i++){
		if (pos[i].size() != pos2[i].size()){
			cout << "NO\n";
			return;
		}
	}
	vector<int>tab(n);
	for (int i = 0; i<3; i++){
		for (int j = 0; j<(int)pos[i].size(); j++){
			tab[pos2[i][j]] = pos[i][j];
		}
	}
	// debug(tab);
	vector<int>b(n, 1);
	segtree seg(n+1, b);
	segtree letters[3];
	for (int i = 0; i<3; i++) letters[i].init(n+1, t, i);
	vector<int>p(n);
	for (int i = 0; i<n; i++) p[tab[i]] = i;
	for (int i = 0; i<n; i++){
		int curr = p[i];
		int alive = (curr ? seg.query(0, curr-1): 0);
		if (!alive) {
			// debug(i);
			seg.update(curr, 0);
			letters[ti(t[curr])].update(curr, 0);
			continue;
		}
		if (t[curr] == 'a'){
			int x = (curr ? letters[1].query(0, curr-1) : 0);
			// debug(alive, x, 'a');
			if (alive != x){
				cout << "NO\n";
				return;
			}
		} else if (t[curr] == 'b'){
			int x = (curr ? letters[2].query(0, curr-1) : 0);
			// debug(alive, x, 'b');
			if (alive != x){
				cout << "NO\n";
				return;
			}
		} else {
			cout << "NO\n";
			return;
		}
		seg.update(curr, 0);
		letters[ti(t[curr])].update(curr, 0);
	}
	cout << "YES\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}