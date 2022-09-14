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

struct Point{
	int a, b, c, i;
	Point(){}
	Point(int _a, int _b, int _c, int _i){
		a = _a, b = _b, c = _c, i = _i;
	}
};

const int MAX = 3e5+7, INF = 1e9+7;
vector<tuple<int, int, int>>s[MAX];

struct segtree{
	int size = (1<<20);
	vector<int>tab;
	
	void clear(){
		tab.assign(2*size+1, INF);
	}
	
	void update(int pos, int val){
		pos += size;
		tab[pos] = min(tab[pos], val);
		while (pos){
			pos/=2;
			tab[pos] = min(tab[2*pos], tab[2*pos+1]);
		}
	}

	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = INF;
		while (r-l>1){
			if (!(l&1)) ans = min(ans, tab[l+1]);
			if (r&1) ans = min(ans, tab[r-1]);
			l/=2;r/=2; 
		}
		return ans;
	}

};

void solve(){
	int n; cin >> n;
	vector<Point>tab;
	vector<int>scaler;
	for (int i = 0; i<n; i++){
		int a, b, c; cin >> a >> b >> c;
		scaler.push_back(a);
		scaler.push_back(b);
		scaler.push_back(c);
		tab.emplace_back(a, b, c, i);
	}
	sort(scaler.begin(), scaler.end());
	scaler.erase(unique(scaler.begin(), scaler.end()), scaler.end());
	for (auto &[a, b, c, i]:tab){ //woww skalowanie bez mapy, zdziwie sie jak zadziala
		a = lower_bound(scaler.begin(), scaler.end(), a)-scaler.begin();
		b = lower_bound(scaler.begin(), scaler.end(), b)-scaler.begin();
		c = lower_bound(scaler.begin(), scaler.end(), c)-scaler.begin();
	}
	vector<int>bad(n+1, 0);
	segtree seg;
	for (int K = 0; K<1; K++){
		sort(tab.begin(), tab.end(), [](auto a, auto b){return tie(a.a, a.b, a.c) < tie(b.a, b.b, b.c);});
		for (auto [a, b, c, i]:tab){
			//debug(a, b, c, i);
			s[a].emplace_back(b, c, i);
		}
		seg.clear();
		for (int curr = 0; curr<MAX; curr++){
			for (auto [b, c, i]:s[curr]){
				int S = seg.query(0, b-1);
				if (S < c){
					bad[i] = 1;
				}
			}	
			for (auto [b, c, i]:s[curr]){
				seg.update(b, c);
			}
			s[curr].clear();
		}
		
		//abc
		//bca
		//cab
		if (K == 0){
			for (auto &[a, b, c, i]:tab) {
				swap(a, b);
				swap(b, c);
			}
		}
		if (K == 1){
			for (auto &[a, b, c, i]:tab){
				swap(a, c);
				swap(a, b);
			}
		}
	}
	vector<int>ans;
	for (int i = 0; i<n; i++) if (!bad[i]) ans.push_back(i+1);
	cout << ans.size() << "\n";
	for (auto x: ans) cout << x << " ";
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
