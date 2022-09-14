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
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

void solve(){
	string s; cin >> s;
	string t; cin >> t;
	s += '.';
	t += '.';

	auto change = [](string s){
		int x = 0;
		vector<int>a;
		for (int i = 0; i<(int)s.size(); i++){
			if (s[i] == '.'){
				a.emplace_back(x);
				x = 0;
			} else {
				x *= 10;
				x += (s[i]-'0');
			}
		}
		return a;
	};
	vector<int>D = {0, 9, 12345, 1, 31, 31, 25, 101001011};
	int all = accumulate(D.begin(), D.end(), 0);

	auto F = [&](string s){
		vector<int>aa = change(s);
		auto Aday = aa[0], Amonth = aa[1], Ayear = aa[2];
		int A_ALL = all * (Ayear-1) - ((Ayear-1)/12) * 31 + ((Ayear-1)/600) * 31; 
		// debug(A_ALL);
		for (int i = 1; i<Amonth; i++) {
			if (i == 4){
				if (Ayear % 12 == 0){
					if (Ayear % 600 != 0){
						continue;
					}
				}
			}
			A_ALL += D[i];
		}
		A_ALL += Aday;
		debug(A_ALL);
		return A_ALL;
	};

	cout << abs(F(t)-F(s)) << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
