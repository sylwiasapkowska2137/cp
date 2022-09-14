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

const int MAX = 1e5+7;
vector<int>rep;
vector<int>cc[2*MAX], smaller[5*MAX];
priority_queue<int>pq[8*MAX];

int Find(int a){
	if (a == rep[a]) return a;
	return rep[a] = Find(rep[a]);
}

bool Union(int a, int b, int t){
	a = rep[a];
	b = rep[b];
	if (a == b) return 0;
	if (cc[a].size() < cc[b].size()) swap(a, b);
	if (t != -1) smaller[t] = cc[b];
	for (auto x: cc[b]) {
		cc[a].push_back(x);
		rep[x] = a;
	}
	cc[b].clear();
	return 1;
}

void solve(){
	int n, m, q; cin >> n >> m >> q;
	vector<pair<int, int>>edges;
	vector<int>val(n+1), who(n+1);
	for (int i = 1; i<=n; i++) {
		cin >> val[i];
		who[val[i]] = i;
	}
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		edges.emplace_back(a, b);
	}
	vector<bool>used(m, 0);
	vector<pair<int, int>>query;
	for (int i = 0; i<q; i++){
		int t, v; cin >> t >> v;
		
		if (t == 2)	{
			v--;
			used[v] = 1;
		}
		query.emplace_back(t, v);
	}
	rep.resize(n+1);
	iota(rep.begin(), rep.end(), 0);
	for (int i = 1; i<=n; i++) cc[i].push_back(i);
	for (int i = 0; i<m; i++){
		if (!used[i]) Union(edges[i].first, edges[i].second, -1);
	}
	for (int i = q-1; i>=0; i--){
		if (query[i].first == 2) Union(edges[query[i].second].first, edges[query[i].second].second, i);
	}
	
	for (int i = 1; i<=n; i++){
		if (Find(i) == i && !cc[i].empty()){
			for (auto x: cc[i]){
				pq[i].push(val[x]);
			}
		}
	}
	int where = n+1;
	for (int i = 0; i<q; i++){
		auto [t, v] = query[i];
		if (t == 1){
			int a = rep[v];
			bool ok = 0;
			while (!pq[a].empty()){
				int x = pq[a].top();
				pq[a].pop();
				if (rep[who[x]] != a) continue;
				ok = 1;
				val[who[x]] = 0;
				cout << x << "\n";
				break;
			}
			if (!ok) cout << "0\n";
		} else {
			for (auto x: smaller[i]){
				rep[x] = where;
				if (val[x]) pq[where].push(val[x]);
			}
			where++;
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
