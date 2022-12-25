//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
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
	vector<vector<bool>>a(n+2, vector<bool>(n+2));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			char c; cin >> c;
			if (c == '1') a[i][j] = 1;
		}
	}
	vector nxt(n+2, vector<short int>(n+2));
	for (int i = 1; i<=n; i++){
		for (int j = n; j>=1; j--){
			if (a[i][j]) nxt[i][j] = 0;
			else nxt[i][j] = nxt[i][j+1]+1;
		}
	}
	// for (int i = 1; i<=n; i++){
	// 	for (int j = 1; j<=n; j++){
	// 		cerr << nxt[i][j] << " ";
	// 	}
	// 	cerr << "\n";
	// }
	int ans = 0;
	for (int k = 1; k<=n; k++){
		vector<int>curr;
		for (int j = 1; j<=n; j++) curr.emplace_back((int)nxt[j][k]);
		// debug(curr);
		stack<int>s;
		vector<int>L(n), R(n);
		for (int i = 0; i<n; i++){
			while (s.size() && curr[s.top()] >= curr[i]) s.pop();
			if (s.empty()) L[i] = -1;
			else L[i] = s.top();
			s.push(i);
		}
		while (s.size()) s.pop();
		for (int i = n-1; i>=0; i--){
			while (s.size() && curr[s.top()] >= curr[i]) s.pop();
			if (s.empty()) R[i] = n+1;
			else R[i] = s.top();
			s.push(i);
		}
		for (int i = 0; i<n; i++){
			int ile = R[i]-L[i]-1;
			if (L[i] == -1 && R[i] == n+1) ile = n;
			else if (L[i] == -1) ile = R[i];
			else if (R[i] == n+1) ile = n-L[i]-1;
			// debug(ile, curr[i]);
			ans = max(ans, ile*curr[i]);
		}
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
