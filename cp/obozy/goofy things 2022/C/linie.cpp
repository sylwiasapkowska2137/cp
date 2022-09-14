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

const long long INF = 1e18;
const int INF2 = 1e9+7;

struct Node{
	long long sum, val, pref, suf;
	int lx, rx, pr, sl; //[lx, rx] for interval with min/max sum, prefix r, suffix left 
	Node (){}
	Node(long long _sum, long long _val, long long _pref, long long _suf, int _lx, int _rx, int _pr, int _sl){
		sum = _sum, val = _val, pref = _pref, suf = _suf, lx = _lx, rx = _rx, pr = _pr, sl = _sl;
	}
};

struct segmin{
	vector<Node>tab;
	Node empty = {INF, INF, INF, INF, INF2, INF2, INF2, INF2};
	int size = 1;
	
	Node comb(Node &a, Node &b){
		if (a.sum == INF) return b;
		if (b.sum == INF) return a;
		Node ans = empty;
		ans.sum = a.sum+b.sum;
		if (a.pref < a.sum + b.pref){
			ans.pref = a.pref;
			ans.pr = a.pr; 
		} else {
			ans.pref = a.sum+b.pref;
			ans.pr = b.pr;
		}
		if (b.suf < b.sum+a.suf){
			ans.suf = b.suf;
			ans.sl = b.sl;
		} else {
			ans.suf = b.sum+a.suf;
			ans.sl = a.sl;
		}
		ans.val = a.val;
		ans.lx = a.lx, ans.rx = a.rx;
		if (ans.val > b.val){
			ans.val = b.val;
			ans.lx = b.lx, ans.rx = b.rx;
		}
		if (ans.val > a.suf+b.pref){
			ans.val = a.suf+b.pref;
			ans.lx = a.sl, ans.rx = b.pr;
		}
		return ans;
	}

	segmin(int n, vector<long long>&a){
		while (size < n) size*=2;
		tab.assign(2*size+1, empty);
		for (int i = 0; i<(int)a.size(); i++) tab[i+size] = {a[i], a[i], a[i], a[i], i, i, i, i};
		for (int i = size-1; i>=1; i--) tab[i] = comb(tab[2*i], tab[2*i+1]); 
	}

	Node query(int x, int lx, int rx, int l, int r){
		if (lx > r || rx < l) return empty;
		if (lx >= l && rx <= r) return tab[x];
		int m = (lx+rx)/2;
		Node a = query(2*x, lx, m, l, r);
		Node b = query(2*x+1, m+1, rx, l, r);
		return comb(a, b);
	}
};

struct segmax{
	vector<Node>tab;
	Node empty = {-INF, -INF, -INF, -INF, -INF2, -INF2, -INF2, -INF2};
	int size = 1;

	Node comb(Node &a, Node &b){
		if (a.sum == -INF) return b;
		if (b.sum == -INF) return a;
		Node ans = empty;
		ans.sum = a.sum+b.sum;
		if (a.pref > a.sum + b.pref){
			ans.pref = a.pref;
			ans.pr = a.pr; 
		} else {
			ans.pref = a.sum+b.pref;
			ans.pr = b.pr;
		}
		if (b.suf > b.sum+a.suf){
			ans.suf = b.suf;
			ans.sl = b.sl;
		} else {
			ans.suf = b.sum+a.suf;
			ans.sl = a.sl;
		}
		ans.val = a.val;
		ans.lx = a.lx, ans.rx = a.rx;
		if (ans.val < b.val){
			ans.val = b.val;
			ans.lx = b.lx, ans.rx = b.rx;
		}
		if (ans.val < a.suf+b.pref){
			ans.val = a.suf+b.pref;
			ans.lx = a.sl, ans.rx = b.pr;
		}
		return ans;
	}

	segmax(int n, vector<long long>&a){
		while (size < n) size*=2;
		tab.assign(2*size+1, empty);
		for (int i = 0; i<(int)a.size(); i++) tab[i+size] = {a[i], a[i], a[i], a[i], i, i, i, i};
		for (int i = size-1; i>=1; i--) tab[i] = comb(tab[2*i], tab[2*i+1]); 
	}

	Node query(int x, int lx, int rx, int l, int r){
		if (lx > r || rx < l) return empty;
		if (lx >= l && rx <= r) return tab[x];
		int m = (lx+rx)/2;
		Node a = query(2*x, lx, m, l, r);
		Node b = query(2*x+1, m+1, rx, l, r);
		return comb(a, b);
	}
};

typedef tuple<long long, int, int> tii;

void solve(){
	int n, k; cin >> n >> k;
	vector<long long>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	segmin smin(n+1, a);
	segmax smax(n+1, a);
	priority_queue<tii> pq; //maksymalne przedzialy z niewziętych przedzialow
	priority_queue<tii, vector<tii>, greater<tii> > pq2; //minimalne przedzialy z wzietych przedzialow
	pq.push({smax.query(1, 0, smax.size-1, 1, n).val, 1, n});
	//cerr << "pq + " << 1 << " " << n << "\n";
	long long sum = 0, ans = 0;
	for (int i = 0; i<k; i++){
		if (pq2.empty()){
			auto [maxi, lx, rx] = pq.top(); pq.pop();
			Node curr = smax.query(1, 0, smax.size-1, lx, rx);
			sum += maxi;
			ans = max(ans, sum);
			pq2.push({smin.query(1, 0, smin.size-1, curr.lx, curr.rx).val, curr.lx, curr.rx});
			if (lx <= curr.lx-1) pq.push({smax.query(1, 0, smax.size-1, lx, curr.lx-1).val, lx, curr.lx-1});
			if (curr.rx+1 <= rx) pq.push({smax.query(1, 0, smax.size-1, curr.rx+1, rx).val, curr.rx+1, rx});
			continue;
		}
		if (pq.empty()){
			auto [rmin, lxm, rxm] = pq2.top(); pq2.pop();
			Node curr = smin.query(1, 0, smin.size-1, lxm, rxm);
			sum -= curr.val;
			ans = max(ans, sum);
			pq.push({smax.query(1, 0, smin.size-1, curr.lx, curr.rx).val, curr.lx, curr.rx});
			if (lxm <= curr.lx-1) pq2.push({smin.query(1, 0, smin.size-1, lxm, curr.lx-1).val, lxm, curr.lx-1});
			if (curr.rx+1 <= rxm) pq2.push({smin.query(1, 0, smin.size-1, curr.rx+1, rxm).val, curr.rx+1, rxm});
			continue;
		}
		auto [maxi, lx, rx] = pq.top();
		auto [rmin, lxm, rxm] = pq2.top(); 
		if (maxi < 0 && rmin > 0) break;
		if (sum - rmin > sum + maxi){
			Node curr = smin.query(1, 0, smin.size-1, lxm, rxm);
			pq2.pop();
			sum -= curr.val;
			ans = max(ans, sum);
			pq.push({smax.query(1, 0, smax.size-1, curr.lx, curr.rx).val, curr.lx, curr.rx});
			if (lxm <= curr.lx-1) pq2.push({smin.query(1, 0, smin.size-1, lxm, curr.lx-1).val, lxm, curr.lx-1});
			if (curr.rx+1 <= rxm) pq2.push({smin.query(1, 0, smin.size-1, curr.rx+1, rxm).val, curr.rx+1, rxm});
		} else {
			pq.pop();
			Node curr = smax.query(1, 0, smax.size-1, lx, rx);
			sum += curr.val;
			ans = max(ans, sum);
			pq2.push({smin.query(1, 0, smin.size-1, curr.lx, curr.rx).val, curr.lx, curr.rx});
			if (lx <= curr.lx-1) pq.push({smax.query(1, 0, smax.size-1, lx, curr.lx-1).val, lx, curr.lx-1});
			if (curr.rx+1 <= rx) pq.push({smax.query(1, 0, smax.size-1, curr.rx+1, rx).val, curr.rx+1, rx});
		}
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
