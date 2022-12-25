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
typedef long double ld;

void solve(){
	int a, b; cin >> a >> b;
	cout << fixed << setprecision(10);
	if (a < b){
		cout << a << "\n";
		return;
	}
	auto f = [&](ld x){
		return x*b + a/(sqrt(1+x));
	};
	int l = 0, r = oo; 
    while (r - l > 3) {
		// debug(l, r);
    	int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        ld f1 = f(m1);   
        ld f2 = f(m2); 
        if (f1 > f2)	
            l = m1;
        else
            r = m2;
    }
	ld ans = oo;
	for (int curr = l; curr <= r; curr++){
		ans = min(ans, f(curr));
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
