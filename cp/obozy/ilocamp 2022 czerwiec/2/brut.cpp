//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;

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

#define int long long
const int oo = 1e18;

int backtrack(vector<int>a, int who){//zwraca kto wygrywa
	if (a.empty()){
		return 1^who;
	}
	if (a.size() == 1){
		if (a[0]&1) return who^1;
		else return who;
	}
	vector<int>b;
	for (auto x: a){
		if (x != 1){
			b.emplace_back(x-1);
		}
	}
	int x = backtrack(b, who^1);
	b = a;
	b.pop_back();
	int y = backtrack(b, who^1);
	if (x && y) return who^1;
	return who;
}


vector<vector<int>>curr;
const int K = 10;

void rek(vector<int>a, int k){
	if (a.size() == k){
		sort(a.begin(), a.end());
		curr.emplace_back(a);
		return;
	}
	for (int i = 1; i<=K; i++){
		a.emplace_back(i);
		rek(a, k);
		a.pop_back();
	}
}

void solve(){
	// vector<vector<int>>ans;
	// rek({}, 3);
	// sort(curr.begin(), curr.end());
	// curr.erase(unique(curr.begin(), curr.end()), curr.end());
	// for (auto a:curr){
	// 	int x = backtrack(a, 0);
	// 	//0 - Anna, 1 - Bogus
	// 	char c = (!x?'A':'B');
	// 	//debug(a, c);
	// 	if (!x){
	// 		ans.emplace_back(a);
	// 	}
	// }
	// debug(ans);
	int n; cin >> n;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int x = backtrack(a, 0);
	char c = (!x?'A':'B');
	cout << c << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
