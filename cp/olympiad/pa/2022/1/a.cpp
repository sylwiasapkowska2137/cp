//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
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
const int oo = 1e18;
const int mod = 1e9+7;
vector<int>f;

void add(int &a, int b){
	a += b;
	if (a >= mod) a-=mod;
}

int mul(int a, int b){
	return (a*b)%mod;
}

void sub(int &a, int b){
	a -= b;
	if (a < 0) a += mod;
}

int power(int a, int b){
	if (!b) return 1LL;
	int k = power(a, b/2);
	k = mul(k, k);
	if (b&1) k = mul(k, a);
	return k;
}

int inv(int a){
	return power(a, mod-2);
}

int nck(int n, int k){
	if (n < k || n < 0 || k < 0) return 0;
	return mul(f[n], mul(inv(f[n-k]), inv(f[k])));
}

int add2(int a, int b){
	a += b;
	if (a >= mod) a-=mod;
	return a;
}

struct query{
	int d, idx, n;
	query(){}
	query(int _d, int _idx, int _n){
		d = _d, idx = _idx, n = _n;
	}
};

int ch(int v){
	if (v < 0) v+=3;
	// debug(v);
	if (v == 0) return 0;
	if (v == 1) return 2;
	if (v == 2) return 1;
	assert(false);
}

pair<int, int>solve(int x){
	return make_pair(ch((1+x)%3), ch((2+x)%3));
}

void solve(){
	int n, q; cin >> n >> q;
	f.resize(n+5);
	f[0] = 1;
	for (int i = 1; i<(int)f.size(); i++) f[i] = mul(f[i-1], i);
	string t; cin >> t;
	int a = 0, b = 0, nnn = 0;
	for (auto c: t){
		if (c == 'C') a++;
		if (c == 'Z') b++;
		if (c == 'N') nnn++;
	}
	// debug(a, b, nnn);
	vector<query>que;
	vector<int>ans(q+1);
	int bad0 = 0, bad1 = 0;
	for (int i = 0; i<n; i++){
		if (i&1){
			if (t[i] == 'Z') bad0++;
			if (t[i] == 'C') bad1++;
		} else {
			if (t[i] == 'Z') bad1++;
			if (t[i] == 'C') bad0++;
		}
	}
	vector<int>what(q+1);
	que.emplace_back(a-b, 0, nnn);
	if (bad0 == 0) what[0]++;
	if (bad1 == 0) what[0]++;
	int h = n/2;
	for (int i = 1; i<=q; i++){
		int x; char c; cin >> x >> c;
		--x;
		if (t[x] == 'N') nnn--;
		if (t[x] == 'C') a--;
		if (t[x] == 'Z') b--;
		if (c == 'N') nnn++;
		if (c == 'C') a++;
		if (c == 'Z') b++;
 
		if (x&1){
			if (t[x] != 'Z' && c == 'Z') bad0++;
			if (t[x] != 'C' && c == 'C') bad1++;
			if (t[x] == 'Z' && c != 'Z') bad0--;
			if (t[x] == 'C' && c != 'C') bad1--;
		} else {
			if (t[x] != 'Z' && c == 'Z') bad1++;
			if (t[x] != 'C' && c == 'C') bad0++;
			if (t[x] == 'Z' && c != 'Z') bad1--;
			if (t[x] == 'C' && c != 'C') bad0--;
		}

		if (bad0 == 0) what[i]++;
		if (bad1 == 0) what[i]++;
		t[x] = c;
		que.emplace_back(a-b, i, nnn);
	}
	sort(que.begin(), que.end(), [](auto x, auto y){return (x.n == y.n) ? x.idx < y.idx : x.n < y.n;});
	vector<int>sum(3), nsum(3);
	int lic = que[0].n;
	for (int i = 0; i<=lic; i++) add(sum[(i%3)], nck(lic, i));
	// debug(what);
	for (auto [diff, idx, nn]:que){
		while (lic < nn){
			for (int i = 0; i<3; i++) nsum[i] = add2(sum[i], sum[i ? i-1 : 2]);
			sum = nsum;
			lic++;
		}
		pair<int, int> curr = solve(nn-diff);
		add(ans[idx], sum[curr.first]);
		add(ans[idx], sum[curr.second]);
		// debug(diff, idx, nn, sum, curr, ans[idx]);
		if (n <= 2) continue;
		if (n%2 == 1){
			if ((h-curr.first)%3 == 0 || (h-curr.second)%3 == 0 || (n-h-curr.first)%3 == 0 || (n-h-curr.second)%3 == 0){
				sub(ans[idx], what[idx]);	
			}
		}
	}
	for (int i = 0; i<=q; i++) cout << ans[i] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	solve();
	
	return 0;
}
