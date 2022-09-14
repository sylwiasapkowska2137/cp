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

#define int long long
const int oo = 1e18, K = 30;

int check(vector<int>x, vector<int>y, int n){
	//x_i ≥ 0
	int a = 0, b = 0, c = 0, d = 0;
	int first_max = 0, second_max = 0, pos = oo;
	for (int i = 0; i<n; i++){
		if (y[i] > 0){
			a = max(a, x[i]);
			d = max(d, y[i]);
		}
		if (y[i] < 0){
			b = max(b, x[i]);
			c = min(c, y[i]);
		}
		if (x[i] > first_max){
			second_max = first_max;
			first_max = x[i];
			pos = y[i];
		} else if (x[i] > second_max){
			second_max = x[i];
		}
	}
	c = abs(c);
	int ans = min({max(a, b), min(2*c+d, 2*d+c)});
	ans = min(ans, abs(pos)+second_max);
	// debug(a, b, c, d);
	if (a <= b) ans = min(ans, a+c);
	if (a >= b) ans = min(ans, b+d);
	// debug(ans);
	return ans;
}

void solve(){
	int n; cin >> n;
	vector<int>x, y;
	for (int i = 0; i<n; i++) {
		int a, b; cin >> a >> b;
		if (!a || !b) continue;
		x.emplace_back(a);
		y.emplace_back(b);
	}
	n = (int)x.size();
	int ans = oo;
	for (int essa = 0; essa < 4; essa++){
		int my = 0, pos = oo;
		for (int i = 0; i<n; i++) {
			if (my > x[i]){
				my = x[i];
				pos = i;
			}
		}
		int sec = 0;
		for (int i = 0; i<n; i++){
			if (i == pos) continue;
			sec = min(sec, x[i]);
		}
		
		int curr = oo;
		if (pos != oo) {
			// debug(sec, pos, y[pos]);
			vector<int>X, Y;
			for (int i = 0; i<n; i++) {
				if ((x[i] >= sec && x[i] <= 0) || (y[pos] >= 0 && y[i] >= 0 && y[i] <= y[pos]) || (y[pos] <= 0 && y[i] <= 0 && y[i] >= y[pos])) continue;
				X.emplace_back(x[i]-sec);
				Y.emplace_back(y[i]-y[pos]);
			}
			// debug(abs(y[pos])+abs(sec));
			// debug(X, Y);
			// debug(check(X, Y, (int)X.size()));
			curr = min(curr, abs(sec)+abs(y[pos])+check(X, Y, (int)X.size()));
		}
		vector<int>X, Y;
		// debug(x, y);
		for (int i = 0; i<n; i++) {
			if ((x[i] >= my && x[i] <= 0) || y[i] == 0) continue;
			X.emplace_back(x[i]-my);
			Y.emplace_back(y[i]);
		}
		// debug(X);
		curr = min(curr, abs(my)+check(X, Y, (int)X.size()));
		// debug(my, curr, X, Y);
		ans = min(ans, curr);
		for (int i = 0; i<n; i++){
			swap(x[i], y[i]);
			x[i] = -x[i];
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
