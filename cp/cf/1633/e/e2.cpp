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
#ifndef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define forn(i, n) for (int i = 0; i < int(n); i++)


struct edge{
	int v, u, w;
};

vector<int> pr, rk;

int getp(int a){
	return a == pr[a] ? a : pr[a] = getp(pr[a]);
}

bool unite(int a, int b){
	a = getp(a), b = getp(b);
	if (a == b) return false;
	if (rk[a] < rk[b]) swap(a, b);
	rk[a] += rk[b];
	pr[b] = a;
	return true;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	pr.resize(n);
	rk.resize(n);
	vector<edge> es(m);
	forn(i, m){
		scanf("%d%d%d", &es[i].v, &es[i].u, &es[i].w);
		--es[i].v, --es[i].u;
		es[i].w *= 2;
	}
	vector<int> ev(1, 0);
	forn(i, m) forn(j, i + 1) ev.push_back((es[i].w + es[j].w) / 2);
	sort(ev.begin(), ev.end());
	ev.resize(unique(ev.begin(), ev.end()) - ev.begin());
	vector<long long> base;
	vector<int> cnt;
	for (int x : ev){
		sort(es.begin(), es.end(), [&x](const edge &a, const edge &b){
			int wa = abs(a.w - x);
			int wb = abs(b.w - x);
			if (wa != wb) return wa < wb;
			return a.w > b.w;
		});
		forn(i, n) pr[i] = i, rk[i] = 1;
		long long cur_base = 0;
		int cur_cnt = 0;
		for (const auto &e : es) if (unite(e.v, e.u)){
			cur_base += abs(e.w - x);
			cur_cnt += x < e.w;
		}
		base.push_back(cur_base);
		cnt.push_back(cur_cnt);
	}
	debug(base);
	debug(cnt);
	return 0;
	int p, k, a, b, c;
	scanf("%d%d%d%d%d", &p, &k, &a, &b, &c);
	int x = 0;
	long long ans = 0;
	forn(q, k){
		if (q < p) scanf("%d", &x);
		else x = (x * 1ll * a + b) % c;
		int y = upper_bound(ev.begin(), ev.end(), 2 * x) - ev.begin() - 1;
		
		int c = (base[y] + (n - 1 - 2 * cnt[y]) * 1ll * (2 * x - ev[y])) / 2;
		ans ^= c;
		cerr << ev[y] << " " << c << "\n";
	}
	cerr << "\n";
	printf("%lld\n", ans);
	return 0;
}
