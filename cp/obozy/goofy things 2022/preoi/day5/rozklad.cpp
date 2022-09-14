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

typedef long double LD;
vector<LL>fact(22);

LL nck(int n, int k){
	return fact[n]/(fact[k]*fact[n-k]);
}

LD power(LD a, int x){
	LD ans = 1;
	for (int i = 1; i<=x; i++){
		ans *= a;
	}
	return ans;
}

void solve(){
	int n; cin >> n;
	fact[0] = 1;
	for (int i = 1; i<=20; i++) fact[i] = (LL)(fact[i-1]*(LL)(i));
	//debug(fact);
	vector<LD>p(5);
	for (int i = 0; i<5; i++) cin >> p[i];
	LD ans = 1;
	for (int i = 0; i<5; i++){
		ans *= (LD)nck(n-i*(n/5), n/5);
		ans *= power(p[i], n/5);
	}
	cout << fixed << setprecision(10) << ans << "\n";
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
