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

struct T{
	vector<int>v;
	int sum = 0, k, idx;
};

struct Tree{
	vector<int>tab;
	int size = 1;

	Tree(int n, vector<int>&a, vector<T>&b, int shift){
		while (size < n) size*=2;
		tab.assign(2*size, oo);
		for (int i = 0; i<(int)a.size(); i++) {
			if (i-shift >= 0 && i-shift < (int)b.size()) {
				tab[i+size] = b[i-shift].k * a[i] - b[i-shift].sum;
			}
		}
		for (int i = size-1; i>=1; i--) tab[i] = min(tab[2*i], tab[2*i+1]);
	}

	int query(int l, int r){
		int ans = oo;
		for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
			if (!(l&1)) ans = min(ans, tab[l+1]);
			if (r&1) ans = min(ans, tab[r-1]);
		}
		return ans;
	}
};

bool cmp(const T &x, const T &y){
	return x.sum * y.k < y.sum * x.k;
}

void solve(){
	int n, m; cin >> n >> m;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	sort(a.rbegin(), a.rend());
	while ((int)a.size() > m) a.pop_back();
	reverse(a.begin(), a.end());
	n = m;
	vector<T>b(m);
	for (int i = 0; i<m; i++){
		int k; cin >> k;
		for (int j = 0; j<k; j++){
			int x; cin >> x;
			b[i].v.emplace_back(x);
			b[i].sum += x;
		}
		b[i].k = k;
		b[i].idx = i;
	}
	sort(b.begin(), b.end(), cmp);
	for (auto [v, sum, k, idx]: b){
		debug(v, sum, k, idx);
	}
	Tree t(m+2, a, b, 0);
	Tree shiftedR(m+2, a, b, 1);
	Tree shiftedL(m+2, a, b, -1);
	int dasie = (t.query(0, m-1) >= 0);
	// debug(dasie);
	vector<vector<int>>ans(m+1);
	int ii = 0;
	for (auto [v, sum, k, idx]: b){
		for (auto curr: v){
			if (k * curr >= sum && dasie) {				
				ans[idx].emplace_back(dasie);
				continue;
			}
			T nowy;
			nowy.sum = sum-curr;
			nowy.k = k-1;
			debug(nowy.sum, nowy.k);
			int L = 0, R = m-1, pos = m-1;
			while (R >= L){
				int mid = (L+R)/2;
				if (b[mid].sum * nowy.k < b[mid].k * nowy.sum){
					pos = mid;
					R = mid-1;
				} else L = mid+1;
			}
			pos = max(0LL, pos-1);
			// if (pos > ii) pos--;
			bool ok = 1;
			debug(curr, pos, ii);
			if (pos <= ii){
				if (pos-1 >= 0) ok &= (t.query(0, pos-1) >= 0);
				if (ii+1 < m) ok &= (t.query(ii+1, m-1) >= 0);
				ok &= (a[pos] * nowy.k >= nowy.sum);
				if (pos + 1 <= ii) ok &= (shiftedR.query(pos+1, ii) >= 0);
			} else {
				if (ii-1 >= 0) ok &= (t.query(0, ii-1) >= 0);
				if (pos+1 < m) ok &= (t.query(pos+1, m-1) >= 0);
				ok &= (a[pos] * nowy.k >= nowy.sum);
				if (ii <= pos-1) ok &= (shiftedL.query(ii, pos-1) >= 0);
			}
			ans[idx].emplace_back((int)(ok));
		}
		ii++;
	}
	for (int i = 0; i<m; i++){
		for (auto v: ans[i]){
			cout << v;
		}
	}
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}