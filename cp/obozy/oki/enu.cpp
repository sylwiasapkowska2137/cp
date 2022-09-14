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

const int MAX = 2e5+7;
LL phi[MAX];

void solve(){
	LL x; cin >> x;
	if (!x) exit(0);
	int L = 1, R = MAX-6;
	int ans = MAX;
	while (R>=L){
		int m = (L+R)/2;
		//debug(m, phi[m]);
		if (phi[m-1] < x){
			ans = m;
			L = m+1;
		} else R = m-1;
	}
	x-=phi[ans-1];
	for (int i = 0; i<=ans; i++){
		if (__gcd(i, ans) == 1){
			x--;
			if (x<=0){
				cout << i << "/" << ans << "\n";
				return;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i<MAX; i++) phi[i] = i;
	for (int i = 2; i<MAX; i++){
		if (phi[i] == i){
			for (int j = i; j<MAX; j+=i){
				phi[j] -= phi[j]/i;
			}
		}
	}
	phi[1] = 2;
	for (int i = 1; i<MAX; i++) phi[i]+=phi[i-1];
	while (1) solve();
	
	return 0;
}
