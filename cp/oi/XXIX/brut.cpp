#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

void __print(int x){cerr << x;}
void __print(long long x){cerr << x;}
void __print(long double x){cerr << x;}
void __print(char x){cerr << "\'" << x << "\'";}
void __print(const char *x){cerr << "\'" << x << "\'";}
void __print(const string &x){cerr << "\"" << x << "\"";}
void __print(bool x) { cerr << (x?"true":"false");}

template<typename T, typename V>
void __print(const pair<T, V>&x){
	cerr << "{";
	__print(x.first);
	cerr << ", ";
	__print(x.second);
	cerr << "}";
}

template<typename T>
void __print(const T &t){
	int f = 0;
	cerr << "{";
	for (auto &i: t) {
		cerr << (f++?", ":""), __print(i);
	}
	cerr << "}";
}

void _print() {cerr << "]\n";}

template<typename T, typename... V>
void _print(T t, V... v){
	__print(t);
	if (sizeof...(v)) cerr << ", ";
	_print(v...);
}

#define int long long
#define debug(x...) cerr << "[" << #x << "] = [";_print(x)

const int mod = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<int>a(n), cnt(n+1, 0), prev(n+1, -1);
	
	function<void(void)> out = [](){
		cout << 0 << endl;
		exit(0);
	};
	
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		if (prev[a[i]] != -1 && i-prev[a[i]]>2) out();
		prev[a[i]] = i;
		cnt[a[i]]++;
	}
	for (int i = 1; i<=n; i++){
		if (cnt[i] > 3) out();
	}
	vector<int>p(n);
	iota(p.begin(), p.end(), 1);
	int ans = 0;
	do{
		bool tmp = 1;
		for (int i = 0; i<n; i++){
			bool ok = 0;
			if (i) ok |= (p[i-1] == a[i]);
			ok |= (p[i] == a[i]);
			if (i < n-1) ok |= (p[i+1] == a[i]);
			if (!ok) tmp = 0;
		}
		/*
		if (tmp) {
			debug(p);
		}
		*/
		ans+=tmp;
		if (ans == mod) ans %= mod;
	
	} while (next_permutation(p.begin(), p.end()));
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();	
	
	return 0;
}
