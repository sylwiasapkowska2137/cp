//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
 
typedef pair<int, int> pii;
typedef pair<LL,LL> pll;
typedef pair<LD,LD> pdd;
 
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<LD> vld;
typedef vector<LL> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
 
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
	int n; cin >> n;
	
	vi a(n);
	unordered_map<int, vi>mapa;
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		mapa[a[i]].push_back(i);
	}
	if (n <= 2){
		cout << "0\n";
		return;
	}
	int A = 2;
	set<int>diffs;
	for (int i = 1; i<n; i++){
		int diff = a[i]-a[0];
		if (diffs.find(diff)!=diffs.end()) continue;
		diffs.insert(diff);
		int curr = i;
		int ans = 2;
		while (curr<n){
			int x = a[curr]+diff;
			//debug(x);
			int X = upper_bound(mapa[x].begin(), mapa[x].end(), curr)-mapa[x].begin();
			if ((int)(mapa[x].size()) <= X) break;
			curr = mapa[x][X];
			//debug(curr);
			ans++;
		}
		//debug(ans);
		A = max(ans, A);
		
	}
	A = n-A;
	if (A&1) A++;
	A/=2;
	cout << A << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
