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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int p(int a, int b){
    return rng()%(b-a+1)+a;
}

void solve(){
	int n = p(1, 5);
	int q = p(1, 5);
	cout << n << " " << q << "\n";
	for (int i = 0; i<n; i++) cout << p(1, 10) << " ";
	cout << "\n";
	while (q--){
		int t = p(0, 1);
		cout << t << " ";
		if (t){
			int l = p(1, n);
			int r = p(1, n);
			if (l > r) swap(l, r);
			cout << l << " " << r << "\n";
		} else {
			int l = p(1, n);
			int r = p(1, n);
			if (l > r) swap(l, r);
			cout << l << " " << r << " " << p(1, 10) << "\n";
		}
	}
}

void solve2(){
	int n = p(1, 2137);
	int k = p(1, 2137);
	cout << n << " " << k << "\n";
	for (int i = 0; i<n; i++) cout << (char)(p(0, 2)+'a');
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve2();
	
	return 0;
}
