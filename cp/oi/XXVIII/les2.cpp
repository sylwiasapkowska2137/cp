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

#define int long long

void solve(){
	int n, d; cin >> n >> d;
	const int oo = 1e18;

	function<int(int)>D = [&](int x){
		return min(x, d-x);
	};

	vector<vector<int>>tab(n);
	for (int i = 0; i<n; i++){
		int x; cin >> x;
		tab[i].resize(x);
		for (int j = 0; j<x; j++){
			cin >> tab[i][j];
		}
	}

	function<void(vector<int>&, vector<int>&)>solve = [&](vector<int>&a, vector<int>&b){
		int A = (int)a.size();
		int B = (int)b.size();
		bool ok = 0;
		if (A < B){
			ok = 1;
			swap(A, B);
			swap(a, b);
		}
		//pozbywanie sie rekwizytów jest obarczone takim samym kosztem jak ich dokladanie
		//pewien prefiks idzie za lewą kulise, pewien sufiks za prawą
		//a ma wiecej elementow niz b
		//exchange arguments chcemy i-ty element z a sparowac z i-tym elementem z b

		int ans = oo;
		int all = 0;
		for (int i = 0; i<A; i++) all += D(a[i]);

		for (int p = 0; p<A; p++){
			int tmp = 0, all2 = all;
			for (int l = 0; l<B; l++){
				tmp += D(abs(b[l]-a[(p+l)%A]));
				all2 -= D(a[(p+l)%A]);
			}
			ans = min(ans, tmp+all2);
			//debug(p, tmp);
		}
		if (ok){
			swap(a, b);
		}
		if (ans == oo) ans = 0;
		cout << ans << "\n";
	};

	for (int i = 1; i<n; i++){
		solve(tab[i-1], tab[i]);
		//return;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
