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
const int mod = 1e9+7;

int inv2, inv6;

int mul(int a, int b){
	return (a*b)%mod;
}

int power(int a, int b){
	if (!b) return 1LL;
	int k = power(a, b/2);
	k = mul(k, k);
	if (b&1) k = mul(k, a);
	return k;
}

void add(int &a, int b){
	a += b;
	if (a >= mod) a-=mod;
}

void sub(int &a, int b){
	a -= b;
	if (a < 0) a+=b;
}

int sum(int a){
	return mul(a, mul(a+1, inv2));
	// return (a*(a+1))/2;
}

int C2(int x){
	return mul(x, mul((x ? x-1 : mod-1), inv2));
	// return (x*(x-1))/2;
}

int square(int a){
	return mul(a, mul(a+1, mul(a+a+1, inv6)));
	// return (a*(a+1)*(a+a+1))/6;
}

int sub2(int a, int b){
	sub(a, b);
	return a;
}

int suma(int i, int x){
	return mul(x-i+1, mul(sub2(square(i), sum(i)), inv2));
	// return ((x-i+1)*(square(i)-sum(i)))/2;
}

void solve(){
	inv2 = power(2, mod-2);
	inv6 = power(6, mod-2);
	int n; cin >> n;
	vector<pair<int, int>>b;
	for (int i = 1; i<=n; i++){
		int x; cin >> x;
		b.emplace_back(x, i);
	}
	sort(b.begin(), b.end(), [](auto x, auto y){
		return x.first == y.first ? x.second < y.second : x.first > y.first;
	});
	vector<int>vis(n+2);
	int ans = 0;
	set<pair<int, int>>s;
	int curr_sum = 0;
	for (auto [val, idx]: b){
		pair<int, int>curr;
		if (!vis[idx-1] && !vis[idx+1]){
			curr = {idx, idx};
		} else if (vis[idx-1] && vis[idx+1]){
			auto it = s.lower_bound({idx, 0});
			// assert (it != s.end());
			curr.second = it->second;
			it--;
			curr.first = it->first;
			sub(curr_sum, C2(it->second-it->first+2));
			s.erase(it);
			it = s.lower_bound({idx, 0});
			sub(curr_sum, C2(it->second-it->first+2));
			s.erase(it);
		} else if (vis[idx-1]){
			auto it = s.lower_bound({idx, 0});
			it--;
			sub(curr_sum, C2(it->second-it->first+2));
			curr = {it->first, idx};
			s.erase(it);
		} else {
			//vis[idx+1]
			auto it = s.lower_bound({idx, 0});
			curr = {idx, it->second};
			sub(curr_sum, C2(it->second-it->first+2));
			s.erase(it);
		}
		// debug(idx, curr);
		int len = curr.second-curr.first+1;
		int I = idx-curr.first+1;
		// assert(suma(I, len) >= 0);
		// assert(suma(len-I+1, len) >= 0);
		add(ans, mul(val, (suma(I, len)+suma(len-I+1, len))));
		add(ans, mul(val, mul(I, mul(len-I+1, curr_sum))));
		// ans += val*I*(len-I+1)*curr_sum;
		add(curr_sum, C2(len+1));
		s.insert(curr);
		vis[idx] = 1;
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
