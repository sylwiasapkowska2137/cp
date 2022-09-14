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

//I love constructive algorithmssss <3333
int n;

bool good(int a, int b){ return (a >= 1 && b >= 1 && a <= n && b <= n);}
#define st first
#define nd second

vector<int>row, col;
set<pair<int, int>>vis;
map<pair<int, int>, pair<int, int>>edges;
int deg[3];

inline void remove(pair<int, int>ptr1){
	if (vis.find(ptr1)==vis.end()){
		vis.insert(ptr1);
		--row[ptr1.st];
		--col[ptr1.nd];		
	}
}

const LL mod = 1e9+7;

LL power(LL a, LL b){
	if (!b) return 1LL;
	LL k = power(a, b/2);
	k = (k*k)%mod;
	if (b&1) k = (k*a)%mod;
	return k;
}

void edge(int a, int b, int c, int d){
	//cerr << "[" << a << ", " << b << "] ----- [" << c << ", " << d << "]\n";
	if (edges.find({a, b}) == edges.end()){
		edges[{a, b}] = {c, d};
		deg[1]++;
	} else {
		if (edges[{a, b}] != make_pair(c, d)){
			deg[1]--;
			deg[2]++;
		} 
	}
}

void solve(){
	cin >> n;
	row.assign(n+1, 0), col.assign(n+1, 0);
	for (int i = 1; i<=n; i++) cin >> row[i];
	for (int i = 1; i<=n; i++) cin >> col[i];
	int s1 = accumulate(row.begin(), row.end(), 0);
	int s2 = accumulate(col.begin(), col.end(), 0);
	if (s1 > 4*n || s2 > 4*n || s1 != s2){
		cout << "0\n";
		return;
	}
	pair<int, int>ptr1 = {1, 1}, ptr2 = {1, 1};
	vis.insert({1, 1});
	--row[1];--col[1];
	int cnt = 0;
	while (cnt <= 4*n){
		cnt++;
		if (ptr1 == ptr2){
			if (row[ptr1.st] > 0 && good(ptr1.st, ptr1.nd+1)){
				ptr1.nd++;
				remove(ptr1);
				edge(ptr1.st, ptr1.nd-1, ptr1.st, ptr1.nd);
				
			} else if (col[ptr1.nd] > 0 && good(ptr1.st+1, ptr1.nd)) {
				ptr1.st++;
				remove(ptr1);
				edge(ptr1.st-1, ptr1.nd, ptr1.st, ptr1.nd);
			}
		} else if (ptr1.st != ptr2.st){
			bool ok = 0;
			if (ptr1.st > ptr2.st){
				ok = 1;
				swap(ptr1, ptr2);
			}
			if (row[ptr1.st] > 0 && good(ptr1.st, ptr1.nd+1)){
				ptr1.nd++;
				remove(ptr1);
				edge(ptr1.st, ptr1.nd-1, ptr1.st, ptr1.nd);
			} else if ((row[ptr1.st+1] > 0 && col[ptr1.nd] > 0) || good(ptr1.st+1, ptr1.nd) && vis.find({ptr1.st+1, ptr1.nd})!=vis.end())	 {
				ptr1.st++;
				remove(ptr1);
				edge(ptr1.st-1, ptr1.nd, ptr1.st, ptr1.nd);
			} else if (good(ptr1.st, ptr1.nd+1)) {
				ptr1.nd++;
				remove(ptr1);
				edge(ptr1.st, ptr1.nd-1, ptr1.st, ptr1.nd);
			}
			if (ok) swap(ptr1, ptr2);
		} else { //ptr1.nd != ptr2.nd
			bool ok = 0;
			if (ptr1.nd > ptr2.nd){
				ok = 1;
				swap(ptr1, ptr2);
			}
			if (col[ptr1.nd] > 0 && good(ptr1.st+1, ptr1.nd)){
				ptr1.st++;
				edge(ptr1.st-1, ptr1.nd, ptr1.st, ptr1.nd);
				remove(ptr1);
			} else if ((row[ptr1.st] > 0 && col[ptr1.nd+1] > 0) || good(ptr1.st, ptr1.nd+1) && vis.find({ptr1.st, ptr1.nd+1})!=vis.end())	 {
				ptr1.nd++;
				remove(ptr1);
				edge(ptr1.st, ptr1.nd-1, ptr1.st, ptr1.nd);
			} else if (good(ptr1.st+1, ptr1.nd)) {
				ptr1.st++;
				edge(ptr1.st-1, ptr1.nd, ptr1.st, ptr1.nd);
				remove(ptr1);
			}
			
			if (ok) swap(ptr1, ptr2);
		}
	}
	//debug(col, row);
	bool ok = 1;
	for (int i = 1; i<=n; i++){
		ok &= (row[i] == 0 && col[i] == 0);
	}
	if (!ok){
		cout << "0\n";
		return;
	}
	//dp
	//debug(deg[1], deg[2]);
	cout << power(2, deg[2]) << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
