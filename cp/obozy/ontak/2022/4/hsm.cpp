//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
const int oo = 1e18, K = 30;
const int mod = 1e9+7;

void subtract(string &k){
	if (k[(int)k.size()-1] == '1'){
		k[(int)k.size()-1] = '0';
		return;
	}
	int pos = (int)k.size()-1;
	for (int i = (int)k.size()-1; i>=0; i--){
		if (k[i] == '1'){
			pos = i;
			break;
		}
	}
	k[pos] = '0';
	for (int i = pos+1; i<(int)k.size(); i++) k[i] = '1';
}

vector<pair<int, int>>classes;
map<pair<int, int>, int>pos;

void rec(int n, string &k){
	if (n == 1){
		classes.emplace_back(0, 0);
		return;
	}
	if (n&1){
		for (int i = 0; i<(n+1)/2; i++){
			classes.emplace_back(n/2, i);
		}
	} 
	rec(n/2, k);
}

int mul(int a, int b){
	return (a*b)%mod;
}

void add(int &a, int b){
	a += b;
	if (a >= mod) a-=mod;
}

int N;

int power(int a, int b){
	if (!b) return 1LL;
	int k = power(a, b/2);
	k = mul(k, k);
	if (b&1) k = mul(k, a);
	return k;
}

int restore(int n, string &k){
	if (n == 1) {
		return (k[0]-'0');
	} 
	int val = restore(n/2, k);
	// debug(n/2, val);
	int ret = 0;
	if (n&1){
		// debug(2137);
		int c = (n+1)/2;
		int f = n/2;
		add(ret, val);
		add(ret, mul(val, power(2, c)));
		add(ret, mul(val, power(2, N*c)));
		add(ret, mul(val, power(2, c*N+c)));
		for (int i = 0; i<(int)k.size(); i++){
			//n/2, i;
			if (pos.find({f, i}) == pos.end()) break;
			if (pos[{f, i}] >= (int)k.size()) break;
			int v = k[pos[{f, i}]]-'0';
			// debug(f, i, v);
			if (v){
				if (i == n-i-1){
					// debug(i, c+n*i);
					add(ret, power(2, f+n*i));
					continue;
				}
				add(ret, power(2, f+n*i));
				add(ret, power(2, f+n*(n-i-1)));
				add(ret, power(2, f*N+i));
				add(ret, power(2, f*N+n-i-1));
			} 
		}
	} else {
		int c = n/2;
		add(ret, val);
		add(ret, mul(val, power(2, c)));
		add(ret, mul(val, power(2, N*c)));
		add(ret, mul(val, power(2, c*N+c)));
	}
	return ret;
}

void solve(){
	int n; cin >> n;
	N = n;
	string k; cin >> k;
	subtract(k);
	// debug(k);
	rec(n, k);
	sort(classes.begin(), classes.end());
	// reverse(classes.begin(), classes.end());
	reverse(k.begin(), k.end());
	while (k.size() < classes.size()) k += "0";
	while (k.size() > classes.size()) k.pop_back();
	reverse(k.begin(), k.end());
	// debug(classes, k);
	for (int i = 0; i<(int)classes.size(); i++) pos[classes[i]] = i;
	cout << restore(n, k) << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
