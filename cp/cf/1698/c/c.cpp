//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
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

#define N \
cout << "NO\n";\
return;\

bool check(vector<int>b){
	int n = (int)b.size();
	for (int i = 0; i<n; i++){
		for (int j = i+1; j<n; j++){
			for (int k = j+1; k<n; k++){
				bool ok = 0;
				for (int l = 0; l<n; l++){
					ok |= (b[i]+b[j]+b[k] == b[l]);
				}
				if (!ok) return 0;
			}
		}
	}
	return 1;
}

void solve(){
	int n; cin >> n;
	vector<int>a(n), b;
	int z = 0, pos = 0, neg = 0;
	for (int i = 0; i<n; i++){
		cin >> a[i];
		if (a[i] > 0) pos++;
		if (a[i] < 0) neg++;
		if (!a[i]) {
			z++;
		} else {
			b.emplace_back(a[i]);
		}
	}
	if (pos > 3 || neg > 3) {
		N
	}
	for (int i = 0; i<min(z, 3LL); i++) b.emplace_back(0);
	if (check(b)) cout << "YES\n";
	else {
		N
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}