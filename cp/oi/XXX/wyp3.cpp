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
	bool operator <= (T he){return *this < he || *this == he;}

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

struct line{
    T a, b;
    line(){}
    line (T _a, T _b){a = _a, b = _b;}
    T f(T x){
        T ret = a * x + b;
        ret.fix();
        return ret;
    }
    T inter(line l){
        if (a == l.a) return T{oo, 1};
        T num = b-l.b; T den = l.a-a;
        return num/den;
        // T x = (b-l.b)/(l.a-a);
        // return x;
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
	
	int ans = 1;
    deque<line>dq;
    dq.emplace_back(t[n].v, T{t[n].d, 1});
	for (int i = n-1; i>=1; i--){
        T rel = VB - t[i].v;
		T TT = {(t[i].x+DB)*rel.b, rel.a}; TT.fix();
        //TT = czas przejscia 
        T S = TT * VB; S.fix();
        // debug(i);
        // S.d();
        while (dq.size() >= 2 && dq.back().f(TT) <= dq[dq.size()-2].f(TT)) dq.pop_back();
        T pp = {pref[i], 1};
        T pos = dq.back().f(TT) - pp; //odjac pref[i]
        line nowy = {t[i].v, T{pref[i], 1}};
        while (dq.size() >= 2 && nowy.inter(dq.front()) <= dq.front().inter(dq[1])) dq.pop_front();
        dq.push_front(nowy);
        // pos.d();
        T diff = pos - S;
        // diff.d();
        if (diff.a >= 0 && diff.b >= 0) ans++;
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
