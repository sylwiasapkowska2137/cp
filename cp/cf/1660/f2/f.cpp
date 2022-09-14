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

struct segtree{
	vector<int>tab;
	int size = 1;

	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
	}

	void update(int x){
		x += size;
		while (x){
			tab[x]++;
			x/=2;
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
} seg[3];

void solve(){
	int n; cin >> n;
	vector<int>a(n+1), pref(n+1), scaler;
	for (int i = 1; i<=n; i++){
		char x; cin >> x;
		if (x == '+') a[i] = 1;
		else a[i] = -1;
		pref[i] = pref[i-1]+a[i];
		scaler.push_back(pref[i]);
	}
	scaler.push_back(0);
	sort(scaler.begin(), scaler.end());
	scaler.erase(unique(scaler.begin(), scaler.end()), scaler.end());
	for (int i = 0; i<3; i++){
		seg[i].init((int)scaler.size()+2);
	}
	map<int, int>mapa;
	for (int i = 0; i<(int)scaler.size(); i++) mapa[scaler[i]] = i;
	//debug(mapa);
	int ans = 0;
	for (int i = 0; i<=n; i++){
		ans += seg[((pref[i]%3)+3)%3].query(mapa[pref[i]], scaler.size()-1);
		seg[((pref[i]%3)+3)%3].update(mapa[pref[i]]);
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}
