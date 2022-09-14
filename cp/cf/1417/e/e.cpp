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

const int K = 30;

struct fenwick{
	vector<int>tab;
	int size = 1;

	void init(int n){
		size = n;
		tab.assign(n+1, 0);
	}

	void clear(){
		fill(tab.begin(), tab.end(), 0);
	}

	void update(int idx){
		for (; idx < size; idx = idx|(idx+1)){
			tab[idx]++;
		}
	}

	int query(int r){
		int ans = 0;
		for (;r >= 0; r = (r&(r+1))-1) ans += tab[r];
        return ans;
	}

	int query(int l, int r){
		return query(r)-query(l-1);
	}
};

void solve(){
	int n; cin >> n;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	vector<int>b = a;
	fenwick fen;
	fen.init(n);
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	LL inv = 0LL;
	for (int j = 0; j<n; j++){
		int x = (int)(lower_bound(b.begin(), b.end(), a[j])-b.begin());
		inv += (LL)fen.query(x+1, n-1);
		fen.update(x);
	}
	int X = 0;
	for (int i = K; i>=0; i--){
		LL inv2 = 0LL;
		b.clear();
		for (auto x: a) b.push_back(x^(1<<i));
		sort(b.begin(), b.end());
		b.erase(unique(b.begin(), b.end()), b.end());
		fen.clear();
		for (int j = 0; j<n; j++){
			int x = (int)(lower_bound(b.begin(), b.end(), (a[j]^(1<<i)))-b.begin());
			inv2 += (LL)fen.query(x+1, n-1);
			fen.update(x);
		}
		if (inv > inv2){
			X += (1<<i);
			for (int j = 0; j<n; j++) a[j] ^= (1<<i);
			inv = inv2;
		}
	}
	cout << inv << " " << X << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
