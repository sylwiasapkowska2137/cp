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

#define int short int
const int K = 30;
// const int mod = 998244353;

int ti(char c){
	return (int)(c-'a');
}

long long count(vector<string>&poz, vector<string>&pion){
	vector<vector<vector<vector<int>>>>dist(2);
	for (int i = 0; i<2; i++){
		int m = (int)poz[i].size();
		dist[i].resize(m+1);
		for (int x = 0; x < m; x++) dist[i][x].assign(K, vector<int>(K));
		for (int a = 0; a < m; a++){
			for (int b = a+1; b < m; b++){
				dist[i][b-a][ti(poz[i][a])][ti(poz[i][b])]++;
			}
		}
	}
	long long ans = 0;
	int t = min((int)poz[0].size(), (int)poz[1].size());
	for (int odl = 2; odl < t; odl++){ 
		for (int shift = 0; shift < (int)pion[0].size(); shift++){
			long long up = 0;
			for (int i = shift; i<(int)pion[0].size(); i++){
				// debug(pion[0][i], pion[1][i-shift]);
				// debug(up, dist[1][odl][ti(pion[0][i])][ti(pion[1][i-shift])]);
				ans += up * (long long)dist[1][odl][ti(pion[0][i])][ti(pion[1][i-shift])];
				if (i-1 >= shift && i - 1 >= 0) up += (long long)dist[0][odl][ti(pion[0][i-1])][ti(pion[1][(i-1)-shift])];
			}
			// debug(ans);
			if (shift == 0) continue;
			long long down = 0;
			for (int i = 0; i < (int)pion[0].size(); i++){
				if (i + shift >= pion[1].size()) break;
				// debug(pion[0][i], pion[1][i+shift]);
				// debug(down, dist[0][odl][ti(pion[0][i])][ti(pion[1][i+shift])]);
				ans += down * (long long)dist[0][odl][ti(pion[0][i])][ti(pion[1][i+shift])];
				if (i-1 >= 0) down += (long long)dist[1][odl][ti(pion[0][i-1])][ti(pion[1][i-1+shift])];	
			}
			// debug(shift, ans);
		}
	}
	return ans;
}

long long check(vector<string>&poz, vector<string>&pion){
	long long ans = 0;
	for (int i = 0; i<2; i++){
		for (int j = 0; j<2; j++){
			if (i) swap(poz[0], poz[1]);
			if (j) swap(pion[0], pion[1]);
			ans += count(poz, pion);
			if (i) swap(poz[0], poz[1]);
			if (j) swap(pion[0], pion[1]);
		}
	}
	return ans;
}

void solve(){
	int n = 4;
	vector<string>a(n);
	vector<string>poz, pion;
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		if (a[i].size() <= 2) {
			cout << "0\n";
			return;
		}
	}
	long long ans = 0;
	for (int mask = 0; mask<(1<<n); mask++){
		if (__builtin_popcountll(mask) == 2){
			// debug(mask);
			poz.clear();pion.clear();
			for (int i = 0; i<n; i++){
				if (mask&(1<<i)) poz.emplace_back(a[i]);
				else pion.emplace_back(a[i]);
			}
			ans += check(poz, pion);
		}
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
