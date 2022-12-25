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
const int mx = 1e5+3;
int rep[mx], sz[mx];
int cnt;

// https://judge.yosupo.jp/submission/68439
namespace fastio {
 
static constexpr int SZ = 1 << 17;
char ibuf[SZ], obuf[SZ];
int pil = 0, pir = 0, por = 0;
 
inline void load()
{
    memmove(ibuf, ibuf + pil, pir - pil);
    pir = pir - pil +
          fread_unlocked(ibuf + pir - pil, 1, SZ - pir + pil, stdin);
    pil = 0;
}
 
inline void rd(char &c)
{
    if (pil + 32 > pir) load();
    c = ibuf[pil++];
}
template <typename T>
inline void rd(T &x)
{
    if (pil + 32 > pir) load();
    char c;
    do
        c = ibuf[pil++];
    while (c < '-');
    [[maybe_unused]] bool minus = false;
    if constexpr (std::is_signed<T>::value == true) {
        if (c == '-') minus = true, c = ibuf[pil++];
    }
    x = 0;
    while (c >= '0') {
        x = x * 10 + (c & 15);
        c = ibuf[pil++];
    }
    if constexpr (std::is_signed<T>::value == true) {
        if (minus) x = -x;
    }
}
inline void rd() {}
template <typename Head, typename... Tail>
inline void rd(Head &head, Tail &...tail)
{
    rd(head);
    rd(tail...);
}
 
inline void skip_space()
{
    if (pil + 32 > pir) load();
    while (ibuf[pil] <= ' ')
        pil++;
}
 
inline void flush()
{
    fwrite_unlocked(obuf, 1, por, stdout);
    por = 0;
}
 
struct Pre {
    char num[40000];
    constexpr Pre() : num()
    {
        for (int i = 0; i < 10000; i++) {
            int n = i;
            for (int j = 3; j >= 0; j--) {
                num[i * 4 + j] = n % 10 + '0';
                n /= 10;
            }
        }
    }
} constexpr pre;
 
struct Post {
    Post() { std::atexit(flush); }
} post;
 
inline void wt(char c)
{
    if (por > SZ - 32) flush();
    obuf[por++] = c;
}
inline void wt(bool b)
{
    if (por > SZ - 32) flush();
    obuf[por++] = b ? '1' : '0';
}
template <typename T>
inline void wt(T x)
{
    if (por > SZ - 32) flush();
    if (!x) {
        obuf[por++] = '0';
        return;
    }
    if constexpr (std::is_signed<T>::value == true) {
        if (x < 0) obuf[por++] = '-', x = -x;
    }
    int i = 12;
    char buf[16];
    while (x >= 10000) {
        memcpy(buf + i, pre.num + (x % 10000) * 4, 4);
        x /= 10000;
        i -= 4;
    }
    if (x < 100) {
        if (x < 10) {
            obuf[por] = '0' + x;
            ++por;
        }
        else {
            uint32_t q = (uint32_t(x) * 205) >> 11;
            uint32_t r = uint32_t(x) - q * 10;
            obuf[por] = '0' + q;
            obuf[por + 1] = '0' + r;
            por += 2;
        }
    }
    else {
        if (x < 1000) {
            memcpy(obuf + por, pre.num + (x << 2) + 1, 3);
            por += 3;
        }
        else {
            memcpy(obuf + por, pre.num + (x << 2), 4);
            por += 4;
        }
    }
    memcpy(obuf + por, buf + i + 4, 12 - i);
    por += 12 - i;
}
 
inline void wt() {}
template <typename Head, typename... Tail>
inline void wt(Head &&head, Tail &&...tail)
{
    wt(head);
    wt(std::forward<Tail>(tail)...);
}
template <typename... Args>
inline void wtn(Args &&...x)
{
    wt(std::forward<Args>(x)...);
    wt('\n');
}
 
} // namespace fastio
using fastio::rd;
using fastio::wtn;

int f(int a){ 
	return a == rep[a] ? a : rep[a] = f(rep[a]);
}

void u(int a, int b){
	a = f(a);b = f(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	rep[b] = a;
	cnt--;
}

void solve(){
	int n, k; rd(n, k);
	vector a(2, vector<int>(n+1));
	int N = n+n;
	vector<vector<pair<int, int>>>edges(N+2);
	for (int rep = 0; rep < 2; rep++){
		for (int i = 1; i<=n; i++){
			rd(a[rep][i]);
		}
	}
	for (int rep = 0; rep < 2; rep++){
		for (int i = 1; i<=n; i++){
			int c = a[rep][i];
			int v = a[rep][i == n ? 1 : i+1];
			if (c < v) edges[max(c, v)].emplace_back(c, v);
			v = a[rep][i == 1 ? n : i-1];
			if (c < v) edges[max(c, v)].emplace_back(c, v);
			v = a[rep^1][i];
			if (c < v) edges[max(c, v)].emplace_back(c, v);
		}
	}	
	vector<int>ans(k+1);
	for (int l = 1; l <= N; l++){
		for (int i = l; i<=N; i++) sz[i] = 1, rep[i] = i;
		cnt = 0;
		for (int r = l; r <= N; r++){
			cnt++;
			for (auto [a, b]:edges[r]) if (a >= l) u(a, b);
			if (cnt <= k) ans[cnt]++;
		}
	}
	for (int i = 1; i<=k; i++) wtn(ans[i]);
	// cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
