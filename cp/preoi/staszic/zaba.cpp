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

LL gcd(LL a, LL b, LL &x, LL &y){
	if (!b){
		x = 1;
		y = 0;
		return a;
	}
	LL x1, y1;
	LL d = gcd(b, a%b, x1, y1);
	x = y1;
	y = x1-y1*(a/b);
	return d;
}

void solve(){
	LL A, B, C, D; cin >> A;
	if (A == -100) exit(0);
	cin >> B >> C >> D;
	if (!A && !B){
		cout << "0 0\n";
		return;
	}
	LL n = D-C;
	LL x = 1, y = 0;
	LL d = gcd(A, B, x, y);
	int k = (D%d);
	int l = d-k;
	if (k <= l) n-=k;
	else n+=l;
	//debug(A, B, n, x, y);
	cout << x*(n/d) << " " << y*(n/d) << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1) solve();
	
	return 0;
}
