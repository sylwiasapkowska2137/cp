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

struct node{
	int s[2] = {-1, -1};
};

struct trie{
	vector<node>tab;
	node empty;
	const int K = 20;

	trie(){
		tab.push_back(empty);
	}

	void add(int x){
		int v = 0;
		for (int i = K-1; i>=0; i--){
			bool s = (x&(1<<i));
			if (tab[v].s[s] == -1){
				tab[v].s[s] = (int)tab.size();
				tab.emplace_back(empty);
			}
			v = tab[v].s[s];
		}
	}

	int minn(int x){
		int v = 0;
		int ans = 0;
		for (int i = K-1; i>=0; i--){
			bool s = (x&(1<<i));
			if (tab[v].s[s] != -1){
				v = tab[v].s[s];
				ans += (s?(1<<i):0);
			} else {
				v = tab[v].s[s^1];
				ans += (s?0:(1<<i));
			}
		}
		return ans;
	}

	int maxx(int x){
		int v = 0;
		int ans = 0;
		for (int i = K-1; i>=0; i--){
			bool s = (x&(1<<i));
			if (tab[v].s[s^1] != -1){
				v = tab[v].s[s^1];
				ans += (s?0:(1<<i));
			} else {
				v = tab[v].s[s];
				ans += (s?(1<<i):0);
			}
		}
		return ans;
	}
};

void solve(){
	int l, r; cin >> l >> r;
	int len = r-l+1;
	vector<int>a(len);
	trie T;
	for (int i = 0; i<len; i++) {
		cin >> a[i];
		T.add(a[i]);
	}	
	// for (int i = 0; i<(int)T.tab.size(); i++){
	// 	debug(T.tab[i].s[0], T.tab[i].s[1]);
	// }
	//return;
	for (int i = 0; i<len; i++){
		//co gdyby i-ty element byl rowny l
		int x = a[i]^l;
		//debug(x);
		int minn = T.minn(x)^x;
		int maxx = T.maxx(x)^x;
		if (minn >= l && maxx <= r){
			cout << x << "\n";
			return;
		}
	}
}


int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}
