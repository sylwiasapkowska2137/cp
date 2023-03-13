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

struct T{
	int a, b; 
	void read(){
		cin >> a >> b;
	}	
	void fix(){
		int d = __gcd(a, b);
		a/=d, b/=d;
	}
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

	bool operator < (T &he) const{
		return a * he.b < b * he.a;
	}

	bool operator == (T &he) const {
		he.fix();
		return a == he.a && b == he.b;
	}

	void d(){
		cerr << a << "/" << b << "\n";
	}

	bool operator <= (T &he) const{
		return *this < he || *this == he;
	}
};

T ckmax(T a, T b){
	if (a < b) return b;
	return a;
}

struct car{
	int x, d; T v;
	void read(){
		cin >> x >> d;
		v.read();
	}
};

void solve(){
	int n, D; T V; cin >> n >> D; V.read();
	vector<car>tab(n+1);
	for (int i = 1; i<=n; i++){
		tab[i].read();
	}
	int ans = 1;
	for (int i = n-1; i>=1; i--){
		auto curr = tab[i];
		auto nxt = tab[i+1];
		int odl = nxt.x-nxt.d-curr.x;
		if (curr.v == nxt.v){
			if (odl >= D){
				ans++;
			}
			continue;
		}
		if (curr.v < nxt.v){ //samochody beda sie od siebie oddalac
			T v = nxt.v - curr.v;
			T t = ckmax(T{0, 1}, T{(D-odl)*v.b, v.a}); // w tym czasie odleglosc staje sie co najmniej D
			t.fix();
			t.d();
			T v_wzgledna = V-curr.v;
			v_wzgledna.d();
			T t2 = {(curr.x+D) * v_wzgledna.b, v_wzgledna.a};
			t2.fix();
			t2.d();
			T v_next_wzg = V-nxt.v;
			v_next_wzg.d();
			T t3 = {(nxt.x-nxt.d) * v_next_wzg.b, v_next_wzg.a};
			t3.fix();
			t3.d();
			if (t <= t3){
				ans++;
			}
		} else { //odleglosc miedzy samochodami sie zmniejsza
			if (odl < D) continue;
			T v = nxt.v - curr.v;
			T t = ckmax(T{0, 1}, T{(D-odl)*v.b, v.a});
			t.fix();
			t.d();
			//w przedziale czasu [0, t] odleglosc jest ok
			T v_next_wzg = V-nxt.v;
			v_next_wzg.d();
			T t3 = {(nxt.x-nxt.d) * v_next_wzg.b, v_next_wzg.a};
			t3.fix();
			t3.d();
			if (t3 <= t){
				ans++;
			}
		}
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
