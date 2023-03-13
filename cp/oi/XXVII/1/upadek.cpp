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
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

void solve(){
	int n; cin >> n;
	vector<int>x(n), h(n);
	for (int i = 0; i<n; i++) cin >> x[i] >> h[i];
	int N1, H1, N2, H2; cin >> N1 >> H1 >> N2 >> H2;
	if (H1 < H2){
		swap(H1, H2);
		swap(N1, N2);
	}
	int ans = 0;
	int L1, L2;
	int div = H1/H2;
	vector<pair<int, int>>used(n+1), real(n+1);
	auto check = [&](int i){
		//idx-1 --> idx
		int dist = abs(x[i] - x[i-1]) - h[i-1];
		if (dist <= 0) return;
		used[i] = {dist/H1, dist%H1};
	};
	auto good = [&](int idx){
		int l1 = L1, l2 = L2;
		int A = used[idx].first;
		int x = used[idx].second;
		
		int t = min(l1, A);
		A -= t;
		l1 -= t;
		l2 -= div*A;
		if (l1 < 0 || l2 < 0) return false;
		// debug(l1, l2);
		int ile = (x+H2-1)/H2;
		t = min(l2, ile);
		ile -= t;
		l2 -= t;
		if (ile) l1--;
		if (l1 < 0 || l2 < 0) return false;
		real[idx] = {L1-l1, L2-l2};
		L1 = l1, L2 = l2;
		return true;
	};
	for (int rep = 0; rep < 2; rep++){
		int R = 0;
		L1 = N1, L2 = N2;
		for (int i = 1; i<n; i++) check(i);
		for (int L = 0; L < n; L++){
			while (R + 1 < n && good(R+1)) R++;
			// debug(L, R);
			ans = max(ans, R-L+1+N1+N2);
			// debug(L, real[L+1]);
			L1 += real[L+1].first;
			L2 += real[L+1].second;
		}
		reverse(x.begin(), x.end());
		reverse(h.begin(), h.end());
		used.assign(n+1, {0, 0});
		real.assign(n+1, {0, 0});
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
