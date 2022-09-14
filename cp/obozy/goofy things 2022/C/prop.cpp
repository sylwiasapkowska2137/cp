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

typedef long double LD;
#define int long long

bool check(int A, int B, int AA, int BB, int A2, int B2, int x, int y){
	if (A*BB<AA*B){
		swap(A, AA);
		swap(B, BB);
	}
	if (A2*y < B2*x){
		swap(A2, x);
		swap(B2, y);
	}
	return B2*y*(A*BB-B*AA)>=B*BB*(A2*y-B2*x);
}

void solve(){
	int n; cin >> n;
	LD f; cin >> f;
	int B = 1e6;
	int A = (int)(f*1e6);
	int one = 0;
	vector<pair<int, int>>tab;
	tab.emplace_back(0, 0);
	for (int i = 1; i<=n; i++){
		char c; cin >> c;
		if (c == '1') one++;
		tab.emplace_back(i, one); //len, number of ones
	}
	sort(tab.begin(), tab.end(), [&](auto a, auto b){return (a.second*B-A*a.first) < b.second*B-A*b.first;});
	//debug(tab);
	cerr << fixed << setprecision(10);
	//debug(A, B);
	int AA = 2137LL*B, BB = 1;
	int idx = n+2137;
	for (int i = 1; i<=n; i++){
		int x = abs(tab[i].second-tab[i-1].second);
		int y = (tab[i].first-tab[i-1].first);
		if (check(A, B, AA, BB, A, B, x, y)){
			AA = x, BB = y;
			idx = min({idx, tab[i].first, tab[i-1].first});
		}
	}
	if (idx > n) cout << "0\n";
	else cout << idx << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
