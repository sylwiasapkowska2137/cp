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

void solve(){
	int n, k, p; cin >> n >> k >> p;
	vector<int>tab(p);
	vector<int>last(n+1, p+1), nxt(p);
	for (int i = 0; i<p; i++) cin >> tab[i];
	for (int i = p-1; i>=0; i--){
		nxt[i] = last[tab[i]];
		last[tab[i]] = i;
	}
	//debug(nxt);
	priority_queue<pair<int,int>>pq; //nxt[v], v
	set<int>now;
	int ans = 0;
	for (int i = 0; i<p; i++){
		if (now.find(tab[i]) != now.end()) continue;		
		if (now.size() >= k){
			pair<int, int>x = pq.top(); pq.pop();
			now.erase(x.second);
			//cerr << "odloz na polke " << x.second << "\n"; 
		}
		//cerr << "zdejmij " << tab[i] << "\n";
		now.insert(tab[i]);
		pq.push({nxt[i], tab[i]});
		ans++;
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
