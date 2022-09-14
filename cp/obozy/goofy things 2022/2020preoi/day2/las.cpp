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
 
int n, sx, sy, ex, ey, p;
LL all;
const int M = 1e5+7;
 
struct segment{
	int x1, y1, x2, y2;
	segment(int xx1 = 0, int yy1 = 0, int xx2 = 0, int yy2 = 0){
		x1 = xx1, y1 = yy1, x2 = xx2, y2 = yy2;
	}
};
 
struct Event{
	int x, y1, y2;

	Event(int xx = 0, int yy1 = 0, int yy2 = 0){
		x = xx, y1 = yy1, y2 = yy2;
	}
};
 
vector<segment>tab;
vector<Event>sweep;

const int S = (1<<17);
pair<int, int>tree[2*S+1];
int lazy[2*S+1];
const int inf = 1e9+7;

pair<int, int>comb(pair<int, int>a, pair<int, int>b){
	if (a.first == b.first) return {a.first, a.second+b.second};
	if (a.first < b.first) return a;
	return b;
}

void clear(){
	memset(lazy, 0, sizeof(lazy));
	for (int i = sy; i<ey; i++) tree[i+S] = {0, 1};
	for (int i = S-1; i>=1; i--) tree[i] = comb(tree[2*i], tree[2*i+1]);
}

void push(int x){
	tree[2*x].first += lazy[x];
	tree[2*x+1].first += lazy[x];
	lazy[2*x] += lazy[x];
	lazy[2*x+1] += lazy[x];
	lazy[x] = 0;
}

void update(int x, int lx, int rx, int l, int r, int val){
	if (lx != rx && lazy[x]) push(x);
	if (lx > r || rx < l) return;
	if (lx >= l && rx <= r){
		tree[x].first += val;
		lazy[x] += val;
		return;
	}
	int m = (lx+rx)/2;
	update(2*x, lx, m, l, r, val);
	update(2*x+1, m+1, rx, l, r, val);
	tree[x] = comb(tree[2*x], tree[2*x+1]);
}
 
void genrect(segment &a, int &r){
    sweep.emplace_back(max({sx, min(a.x1, a.x2)-r}), max({sy, min(a.y1, a.y2)-r}), min({ey, max(a.y1, a.y2)+r}));
	sweep.emplace_back(min({ex, max(a.x1, a.x2)+r}), max({sy, min(a.y1, a.y2)-r}), -min({ey, max(a.y1, a.y2)+r}));
}
 
bool check(int &mid){
	clear();
	sweep.clear();
	for (int i = 0; i<n; i++) genrect(tab[i], mid);
	sort(sweep.begin(), sweep.end(), [](auto a, auto b){return a.x < b.x;});
	int ptr = 0;
	LL ans = (LL)(ex-sx+1LL)*(LL)(ey-sy);
	for (int i = sx; i<=ex; i++){
		while (ptr < (int)sweep.size() && sweep[ptr].x <= i){
			if (sweep[ptr].y2 < 0) update(1, 0, S-1, sweep[ptr].y1, -sweep[ptr].y2-1, -1);
			else update(1, 0, S-1, sweep[ptr].y1, sweep[ptr].y2-1, 1);
			ptr++;
		}
		if (!tree[1].first) ans -= (LL)tree[1].second;
	}
	return (ans*100LL >= all*(LL)p);
}
 
void read(int &num){
    bool negative = false;
    register int c;
    num = 0;
    c = getchar();
    if (c=='-'){
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        num = num *10 + c - 48;
    if (negative) num *= -1;
}
 
void solve(){
	read(n);
	tab.resize(n);
	for (int i = 0; i<n; i++) {
		read(tab[i].x1);read(tab[i].y1);read(tab[i].x2);read(tab[i].y2);
	}
	read(p); read(sx), read(sy), read(ex), read(ey);
	all = (LL)(ex-sx)*(LL)(ey-sy);
	for (int i = 0; i<=2*S; i++) tree[i] = {inf, 0};
	int L = 0, R = 1e5, ans = 1e5;
	while (R>=L){
		int m = (L+R)/2;
		if (check(m)){
			ans = m;
			R = m-1;
		} else L = m+1;
	}
	cout << ans << "\n";
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}