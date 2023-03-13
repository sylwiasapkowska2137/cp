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

int gcd(int a, int b){return b ? gcd(b, a%b) : a;}

struct T{
	int a, b;
	T(){}
	T(int _a, int _b){a = _a, b = _b;}
	void read(){
		cin >> a >> b;
		this->fix();
	}
	void fix(){
		int d = gcd(a, b);
		a/=d, b/=d;
	}

	bool operator < (T he) const{return a * he.b < b * he.a;}
	void d(){cerr << a << "/" << b << "\n";}
	bool operator == (T &he) const { return a == he.a && b == he.b;}
	bool operator <= (T &he) const{return *this < he || *this == he;}

	T operator+(T &he) const{
		T ret = {a*he.b+b*he.a, b*he.b};
		ret.fix();
		return ret;
	}

	T operator-(T&he) const{
		T ret = {a*he.b - b*he.a, b*he.b};
		ret.fix();
		return ret;
	}

	T operator *(T &he) const{
		T ret = {a * he.a, b * he.b};
		ret.fix();
		return ret;
	}
	
	T operator/(T &he) const {
		T rev = {he.b, he.a};
		return *this * rev;
	}
};

struct car{
	int x, d; T v;
	void read(){
		cin >> x >> d;
		v.read();
	}
};

void solve(){
	int n, DB; T VB; cin >> n >> DB; VB.read();
	vector<car>t(n+1);
	vector<int>pref(n+1);
	for (int i = 1; i<=n; i++) {
		t[i].read();
		pref[i] = pref[i-1] + t[i].d;
	}
	stack<int>s;
	s.push(n);
	int ans = 1;
	for (int i = n-1; i>=1; i--){
		while (s.size() && t[i].v < t[s.top()].v) s.pop();
		T rel = VB - t[i].v;
		T TT = {(t[i].x+DB)*rel.b, rel.a}; TT.fix();
		// TT.d();
		if (s.empty()){
			T wzgl = t[i+1].v - t[i].v;
			int odl = t[i+1].x - t[i].x - t[i+1].d;
			T curr = {(DB-odl)*wzgl.b, wzgl.a}; curr.fix();
			if (curr <= TT){
				ans++;
			}
		} else {
			// debug(i, s.top());
			int sd = pref[s.top()]-pref[i];
			int odl = t[s.top()].x - sd - t[i].x;
			// debug(odl);
			if (t[i].v == t[s.top()].v){
				if (odl >= DB) {
					ans++;
				}
			} else {
				//v_i > v_{s.top()}
				T wzgl = t[i].v - t[s.top()].v;
				T curr = {odl*wzgl.b, wzgl.a}; curr.fix();
				// curr.d();
				if (TT <= curr){
					ans++;
				}
			}
		}
		s.push(i);
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
