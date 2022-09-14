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

const int MAX = 1e6+7;
vector<int>deg, graf[MAX];
int n;
const int INF = 1e9+7;

bool check(int mid){
	queue<int>q;
	vector<int>vis(n+1, 0);
	vector<int>d = deg;
	for (int i = 1; i<=n; i++) {
		if (deg[i]<mid) {
			q.push(i);
			vis[i] = 1;
		}
	}
	while (!q.empty()){
		int v = q.front();
		q.pop();
		for (auto x: graf[v]){
			d[x]--;
			if (!vis[x]){
				if (d[x] < mid){
					vis[x] = 1;
					q.push(x);
				}
			}
		}
	}
	int ans = INF;
	//debug(mid, vis);
	for (int i = 1; i<=n; i++) if (!vis[i]) ans = min(ans, d[i]);
	//debug(ans);
	return (ans >= mid && ans != INF);
}

void solve(){
	int m; cin >> n >> m;
	deg.assign(n+1, 0);
	for (int i = 0;i<m; i++){
		int a, b; cin >> a >> b;
		deg[a]++;
		deg[b]++;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	int l = 1, ans = 1, r = n;
	while (r>=l){
		int mid = (l+r)/2;
		if (check(mid)){
			ans = mid;
			l = mid+1;
		} else r = mid-1;
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
