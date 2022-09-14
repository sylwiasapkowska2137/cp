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

LL pairs(LL x){
	return x*(x-1)/2;
}

void solve(){
	int n, k; cin >> n >> k;
	vector<LL>cnt((1<<k)+1, 0);
	for (int i = 0; i<n; i++){
		string s; cin >> s;
		int curr = 0;
		for (int j = 0; j<k; j++){
			if (s[j] == '1'){
				curr += (1<<j);
			}
		}
		cnt[curr]++;
	}
	LL ans = 0LL;
	for (int a = 1; a<(1<<k); a++){
		if (!cnt[a]) continue;
		for (int b = a; b<(1<<k); b++){
			if (a == b) ans += (LL)pairs(cnt[a]);
			else {
				if ((a&b) != 0) ans += (LL)cnt[a]*(LL)cnt[b];
			}
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
