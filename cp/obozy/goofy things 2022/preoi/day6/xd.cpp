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


const int MAX = 450;
map<int, set<int>>cnt[MAX];
int s;

void add(vector<int>&a, int idx, int val){
	cnt[idx/s][a[idx]].erase(idx);
	a[idx]+=val;
	cnt[idx/s][a[idx]].insert(idx);
}

const int INF = 1e9+7;

void solve(){
	int n, q; cin >> n >> q;
	vector<int>a(n);
	s = max(1, (int)sqrt(n)+1);
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		cnt[i/s][a[i]].insert(i);
	}
	//debug(s);
	vector<int>to_add(s, 0);
	while (q--){
		int t; cin >> t;
		if (t == 1){
			int l, r, v; cin >> l >> r >> v;
			--l;--r;
			int L = l/s, R = r/s;
			//debug(L, R);
			if (L == R){
				for (int i = l; i<=r; i++) add(a, i, v);
				continue;
			}
			for (int i = l; i<(L+1)*s; i++) add(a, i, v);
			for (int i = L+1; i<R; i++) to_add[i]+=v;
			for (int i = R*s; i<=r; i++) add(a, i, v);
		} else {
			int x; cin >> x;
			int L = INF, R = -1;
			for (int i = 0; i<=s; i++){
				if (!cnt[i][x-to_add[i]].empty()){
					L = min(L, *cnt[i][x-to_add[i]].begin());
					R = max(R, *cnt[i][x-to_add[i]].rbegin());
				}
			}
			cout << ((L == INF)?-1:R-L) << "\n";
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
