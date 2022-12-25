//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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

const int oo = 1e9+7;
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
}
 
} // namespace fastio
using fastio::rd;
using fastio::wtn;


void solve(){
	int n; rd(n);
	vector<int>p(n+1);
	for (int i = 1; i<=n; i++) rd(p[i]);
	vector<vector<int>>g(n+1);
	for (int i = 1; i<=n; i++){
		for (int j = i+1; j<=n; j++){
			if (p[i] > p[j]){
				g[i].emplace_back(j);
				g[j].emplace_back(i);
				debug(i, j);
			}
		}
	}
	queue<int>q;
	vector<int>dist(n+1, oo);
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++) dist[j] = oo;	
		q.push(i);
		dist[i] = 0;
		while (q.size()){
			int v = q.front();q.pop();
			for (auto x: g[v]){
				if (dist[x] == oo){
					dist[x] = dist[v]+1;
					q.push(x);
				}
			}
		}
		int ans = 0;
		for (int j = 1; j<=n; j++){
			if (dist[j]!=oo) {
				ans+=dist[j];
			}
		}
		wtn(ans, ' ');
	}
	wtn('\n');
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
