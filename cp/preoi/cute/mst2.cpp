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

struct E{
	int a, b, w, c; 
	E(){}
	E(int _a, int _b, int _w, int _c){
		a = _a, b = _b, w = _w, c = _c;
	}
};

vector<E>e;
vector<int>rep, sz;

void init(int n){
	rep.resize(n);
	iota(rep.begin(), rep.end(), 0);
	sz.assign(n+1, 1);
}

int Find(int a){
	if (a == rep[a]) return a;
	return rep[a] = Find(rep[a]);
}

bool Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if (a == b) return 0;
	if (sz[a] < sz[b]) swap(a, b);
	sz[a]+=sz[b];
	rep[b] = a;
	return 1;
}

pair<int, int> solve(int cost, int&n){
	vector<E>curr;
	for (auto [a, b, w, c]:e){
		if (!c) curr.emplace_back(a, b, w+cost, 1); 
		else curr.emplace_back(a, b, w, 0);
	}
	sort(curr.begin(), curr.end(), [](auto a, auto b){
		if (a.w == b.w) return a.c < b.c;
		return a.w < b.w;
	});
	init(n+1);
	int ans = 0;
	int used = 0;
	for (auto [a, b, w, c]: curr){
		if (Union(a, b)) {
			//debug(a, b, w, c);
			ans += w;
			used += c;
		}
	}
	return {ans, used};
}


void solve(){
	int n, m, k; cin >> n >> m >> k;
	int black = 0;
	for (int i = 0; i<m; i++){
		int a, b, w, c; cin >> a >> b >> w >> c;
		e.emplace_back(a, b, w, c);
		black += (c^1);
	}
	if (black < k){
		cout << "-1\n";
		return;
	}
	const int INF = (1<<10);
	int ans = INF, L = -INF, R = INF;
	int X = 0;
    pair<int, int>xd = solve(-INF, n);
    if (xd.second == k){
        X = 1;
    }
    while (R>=L){
		int mid = (L+R)/2;
		pair<int, int> x = solve(mid, n);
		//debug(mid, x);
		if (x.second + X <= k){
			ans = mid;
			R = mid-1;
		} else L = mid+1;
	}
	//debug(ans);
    if (abs(ans) >= INF){
        cout << "-1\n";
        return;
    }
	pair<int, int> x = solve(ans, n);
    cout << x.first - k*ans << "\n";
	return;
    //debug(k, x);
    /*
	if (x.second <= k){
		if (ans == -INF){
			int l = -INF, r = INF;
			while (r>=l){
				int mid = (l+r)/2;
				pair<int, int>z = solve(mid, n);
				if (z.second < k) r = mid-1;
				else {
					ans = mid;
					l = mid+1;
				}
			}
			//debug(ans);
			if (ans == -INF) {
				cout << "-1\n";
				return;
			}
		} 
		pair<int, int>y = solve(ans, n);
		cout << y.first-k*ans << "\n";
	} else cout << "-1\n";
    */
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
