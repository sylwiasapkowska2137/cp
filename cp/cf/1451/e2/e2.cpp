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

int query(int t, int a, int b){
	if (t == 1) cout << "AND ";
	if (t == 2) cout << "OR ";
	if (t == 3) cout << "XOR ";
	cout << a << " " << b << "\n";
	cout.flush();
	int x; cin >> x;
	return x;
}

void solve(){
	int n; cin >> n;
	vector<int>x(n+1);
	vector<pair<int, int>> s;
	map<int, vector<int>>cnt;
	for (int i = 2; i<=n; i++){
		x[i] = query(3, 1, i);
		s.emplace_back(x[i], i);
		cnt[x[i]].emplace_back(i);	
	}
	vector<int>a(n+1);
	sort(s.begin(), s.end());
	bool ok = 0;
	for (int i = 1; i<(int)s.size(); i++){
		if (s[i].first == s[i-1].first){
			ok = 1;
			int v = query(1, s[i].second, s[i-1].second);
			a[1] = x[s[i].second]^v;
			break;
		}
	}
	int k = 0;
	while ((1<<k) < n) k++;
	// debug(k);
	if (!ok){
		int aa, b;
		for (int i = 0; i<n; i++){
			int neg = 0;
			for (int j = 0; j<k; j++){
				if (i&(1<<j)) {
					;
				} else {
					neg += (1<<j);
				}
			}
			// debug(i, neg);
			if (cnt[i].size() && cnt[neg].size()){
				aa = cnt[i][0];
				b = cnt[neg][0];
				break;
			}
		}
		// debug(aa, b);
		// return;
		int c = 1;
		for (int i = 1; i<=n; i++){
			if (i == aa || i == b) continue;
			c = i;
			break;
		}
		int ab = n-1;
		int bc = x[b]^x[c] + 2 * query(1, b, c);
		int ac = x[c] + 2 * query(1, aa, c);
		int sum = (ab+bc+ac)/2;
		a[1] = sum-bc;
	}	
	for (int i = 2; i<=n; i++) a[i] = a[1]^x[i];
	cout << "! ";
	for (int i = 1; i<=n; i++) cout << a[i] << " ";
	cout << "\n";
	cout.flush();
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}