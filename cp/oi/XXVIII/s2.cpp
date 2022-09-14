//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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

#define int LL
const int MAX = 1e8+1;
bitset<MAX>p;

void sito(){
	p.reset();
	p[1] = 1;
	for (int i = 2; i<=MAX; i++){
		if (p[i] == 0){
			for (int j=i*i; j<=MAX; j+=i){
				p[j] = 1;
			}
		}
	}
}

LL power(LL a, LL b, LL mod){
	if (!b) return 1LL;
	LL k = power(a, b/2, mod);
	k = (k*k)%mod;
	if (b&1) k = (k*a)%mod;
	return k;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int pp(int a, int b){
	return a+rng()%(b-a+1);
}

bool is_prime(LL n){
	if (n <= 1 || n == 4)  return false;
   	if (n <= 3) return true;
	for (int k = 0; k<3; k++){
		int a = pp(2, n-2);
		if (__gcd(a, n) != 1) return 0;
		if (power(a, n-1, n) != 1) return 0;
	}
	return 1;
}

void solve(){
	int n; cin >> n;
	function<void(int, int)>out = [](int l = -1, int r = -1){
		if (l == -1) cout << "NIE\n";
		else cout << l << " " << r << "\n";
		exit(0);
	};
	if (n == 1) out(-1, -1);
	if (is_prime(n)) out(n, n);
	int x = n/2, y = n-x, nearest = -1;
	while(1) {
		if (is_prime(x)) {
			nearest = x; break;
		}
		if (is_prime(y)) {
			nearest = y; break;
		}
		x--;y++;
	}
	if (is_prime(n-nearest) && nearest*2!=n) out(nearest, n-nearest);
	sito();	
	int L = 2, sum = 2;
	for (int R = 3; R<=MAX; R+=2){
		if (!p[R]) sum += R;
		else continue;
		while (sum > n || (sum == n && p[L])){
			if (!p[L]) sum -= L;
			L++;
		}
		if (sum == n) out(L, R);
	}
	//znajduje wszystkie przedzialy dla któtych prawy koniec ≤1e8
	//ale lewy juz nie musi
	//tych kolejnych liczb będzie okolo 1e11/1e8 = 1000
	for (int k = 2; k<=1100; k++){
		int ave = n/k;
		int ile = 0;
		vector<int>curr;
		if (is_prime(ave)) curr.emplace_back(ave);
		while (ile < k && ave > 1){
			ave--;
			if (is_prime(ave)){
				curr.emplace_back(ave);
				ile++;
			}
		} 
		ave = n/k;
		while (ile < k && ave < n){
			ave++;
			if (is_prime(ave)){
				curr.emplace_back(ave);
				ile++;
			}
		} 
		sort(curr.begin(), curr.end());
		int L = 0, sum = 0;
		for (int R = 0; R<(int)curr.size(); R++){
			sum += curr[R];
			if (sum == n) out(curr[L], curr[R]);
			while (sum > n){
				sum -= curr[L];
				L++;
			}
		}
	}
	out(-1, -1);
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
