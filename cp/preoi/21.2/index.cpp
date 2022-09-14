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

vector<vector<int>> c;
int R = 0;

vector<int> suffix_array(string &s){
	s.push_back('$');
	int n = (int)s.size();
	//k = 0;
	vector<pair<char, int>>a;
	for (int i = 0; i<n; i++) a.emplace_back(s[i], i);
	sort(a.begin(), a.end());
	vector<int>p(n);
	int S = 1;
	while (S < n) {
		S*=2;
		R++;
	}
	c.resize(R+1, vector<int>(n+1, 0));
	for (int i = 0; i<n; i++) p[i] = a[i].second;
	c[0][p[0]] = 0;
	for (int i = 1; i<n; i++){
		if (a[i].first == a[i-1].first) c[0][p[i]] = c[0][p[i-1]];
		else c[0][p[i]] = c[0][p[i-1]]+1;
	}

	int k = 0;
	while ((1<<k) < n){
		//k -> k+1
		vector<pair<pair<int, int>, int>>a;
		for (int i = 0; i<n; i++) a.push_back({{c[k][i], c[k][(i+(1<<k))%n]}, i});
		sort(a.begin(), a.end());
		for (int i = 0; i<(int)a.size(); i++) p[i] = a[i].second;
		c[k+1][p[0]] = 0;
		for (int i = 1; i<n; i++){
			if (a[i].first == a[i-1].first) c[k+1][p[i]] = c[k+1][p[i-1]];
			else c[k+1][p[i]] = c[k+1][p[i-1]]+1;
		}
		k++;
	}
	return p;
}


int n;

int LCP(int i, int j){
	int ans = 0;
	for (int k = R; k>=0; k--){
		if (c[k][i] == c[k][j]){
			ans += (1<<k);
			i += (1<<k);
			j += (1<<k);
			//i%=n; j%=n;
		}
	}
	return ans;
}

vector<int> find_lcp(vector<int>&p, vector<int>&bad){
	vector<int>p2;
	for (auto x: p) if (!bad[x]) p2.push_back(x);
	vector<int>lcp;
	for (int i = 1; i<(int)p2.size(); i++){
		lcp.push_back(LCP(p2[i-1], p2[i]));
	}
	return lcp;
}

void solve(){
	cin >> n;
	LL ans = 0LL;
	string s; cin >> s;
	vector<int>bad(n, 0); 
	for (int i = 0; i<n; i++) {
		char c; cin >> c;
		if (c == '1') bad[i] = 1;
		else ans = i+1;
	}
	reverse(s.begin(), s.end());
	reverse(bad.begin(), bad.end());
	vector<int>p = suffix_array(s);
	//debug(p);
	//for (auto x: p)	cout << s.substr(x, n+1-x) << "\n";
	vector<int>lcp = find_lcp(p, bad);
	//debug(s);
	//debug(lcp);
	stack<pair<int, int>>st;
	vector<int>prawo((int)lcp.size(), (int)lcp.size());
	for (int i = (int)lcp.size()-1; i>=0; i--){
		while (!st.empty() && st.top().first >= lcp[i]) st.pop();
		if (!st.empty()) prawo[i] = st.top().second;
		st.push({lcp[i], i});
	}
	while (!st.empty()) st.pop();
	vector<int>lewo((int)lcp.size(), -1);
	for (int i = 0; i<(int)lcp.size(); i++){
		while (!st.empty() && st.top().first >= lcp[i]) st.pop();
		if (!st.empty()) lewo[i] = st.top().second;
		st.push({lcp[i], i});
	}
	//debug(lewo);
	//debug(prawo);
	//debug(ans);
	for (int i = 0; i<(int)prawo.size(); i++){
		LL x = (LL)(prawo[i]-lewo[i]);
		ans = max(ans, x*lcp[i]);
		//debug(i, x, x*lcp[i]);
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
