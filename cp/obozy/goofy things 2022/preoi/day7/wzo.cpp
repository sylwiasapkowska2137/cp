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

const int INF = 1e9+7;

void solve(){
	string s; cin >> s;
	int k; cin >> k;
	int n = (int)s.size();
	vector<int>cnt(30, 0);
	int diff = 0;
	int r = 0;
	int ans = INF, L, R;
	for (int l = 0; l<n; l++){
		while (r<n && diff < k){
			cnt[s[r]-'a']++;
			if (cnt[s[r]-'a'] == 1) diff++;
			r++;
		}
		if (diff >= k){
			if (ans > r-l){
				ans = r-l;
				L = l, R = r-1;
			}
		}
		cnt[s[l]-'a']--;
		if (!cnt[s[l]-'a']) diff--;
	}
	if (ans == INF){
		cout << "BRAK\n";
	} else {
		cout << L+1 << " " << R+1 << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
