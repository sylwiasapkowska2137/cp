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

const int MAX = 120000;
vector<pair<int, int>>graf[MAX];
int n, k;
vector<bool>vis;
const int INF = 1e9+7;
vector<int>smaller, bigger;

void dfs(int v, int pa, int prev){
	vis[v] = 1;
	for (auto [x, c]:graf[v]){
		if (x!=pa && c > prev){
			dfs(x, v, c);
		}
	}
}


struct Event{
	char type;
	int a, b, d;
	
	void read(int &idx){
		cin >> type;
		if (type == 'S'){
			cin >> a >> b;
			d = idx++;
			graf[a].push_back({b, d});
			graf[b].push_back({a, d});
			int y = smaller[a];
			smaller[a] += bigger[b]+1;
			int x = bigger[a];
			bigger[a] += smaller[b]+1;
			smaller[b] += x+1;
			bigger[b] += y+1;
		} else if (type == 'Q'){
			cin >> a >> d;
			vis.assign(n+1, 0);
			dfs(d, d, -INF);
			cout << (vis[a]?"yes":"no") << "\n";
		} else {
			cin >> d;
			cout << smaller[d]+1 << "\n";
		}
	}
};

void solve(){
	cin >> n >> k;
	smaller.assign(n+1, 0);
	bigger.assign(n+1, 0);
	int idx = 1;
	vector<Event>tab(n+k-1);
	for (int i = 0; i<n+k-1; i++){
		tab[i].read(idx);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
