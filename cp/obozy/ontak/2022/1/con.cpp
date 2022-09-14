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
const int oo = 1e18, K = 30;

struct item{
	int l, r, w;
	void read(){
		cin >> l >> r >> w;
	}	
};

void solve(){
	int n, k; cin >> n >> k;
	vector<item>tab(n);
	vector<int>scaler;
	for (int i = 0; i<n; i++) {
		tab[i].read();
		scaler.emplace_back(tab[i].l);
		scaler.emplace_back(tab[i].r);
	}
	sort(scaler.begin(), scaler.end());
	scaler.erase(unique(scaler.begin(), scaler.end()), scaler.end());
	int s = (int)scaler.size(), all = 0;
	for (auto &[l, r, w]:tab){
		l = lower_bound(scaler.begin(), scaler.end(), l)-scaler.begin()+1;
		r = lower_bound(scaler.begin(), scaler.end(), r)-scaler.begin()+1;
		all += w;
		// debug(l, r, w);
	}
	// cerr << "1";
	vector<vector<int>>c(s+1, vector<int>(s+1));
	vector<pair<int, int>>t;
	multiset<int>secik;
	for (int L = 1; L<=s; L++){
		t.clear();
		for (auto [l, r, c]:tab) if (l >= L) t.emplace_back(r, c);
		sort(t.begin(), t.end());
		int ptr = 0, sum = 0;
		secik.clear();
		for (int R = L; R<=s; R++){
			while (ptr < (int)t.size() && t[ptr].first <= R){
				if (secik.size() < k) {
					secik.insert(t[ptr].second);
					sum += t[ptr].second;
				} else if (secik.size() == k && *secik.begin() < t[ptr].second){
					sum -= *secik.begin();
					secik.erase(secik.begin());
					secik.insert(t[ptr].second);
					sum += t[ptr].second;
				}
				ptr++;
			}
			c[L][R] = sum;
			// debug(L, R, c[L][R]);
		}
	}
	// cerr << "2";
	// return;
	vector<int>R(s+1);
	vector<int> dp(s+1);
	for (int i = 0; i<=s; i++){
		for (int j = 0; j<n; j++){
			if (tab[j].r <= i) R[i] = max(R[i], tab[j].r);
		}
	}
	// debug(R);
	// cerr << "3";
	for (int i = 0; i<=s; i++){
		dp[i] = c[1][R[i]];
		for (int j = 0; j<i; j++){
			if (R[j] < R[i]) {
				dp[i] = max(dp[i], dp[j]+c[R[j]+1][R[i]]);
			} else break;
		}
	}
	// debug(dp);
	cout << all-*max_element(dp.begin(), dp.end()) << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}