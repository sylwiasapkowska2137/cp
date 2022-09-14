//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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
const int oo = 1e18, K = 30;

vector<int>Find(vector<int>&a){
	int n = (int)a.size();
	vector<int>tail(n), prev(n, -1);
	int len = 1;
	for (int i = 1; i<n; i++){
		if (a[i] < a[tail[0]]) tail[0] = i;
		else if (a[i] > a[tail[len-1]]){
			prev[i] = tail[len-1];
			tail[len++] = i;
		} else {
			int l = -1, r = len-1;
			while (r-l>1){
				int m = (l+r)/2;
				if (a[tail[m]] >= a[i]) r = m;
				else l = m;
			}
			int pos = r;
			prev[i] = tail[pos-1];
			tail[pos] = i;
		}
	}
	vector<int>ret;
	for (int i = tail[len-1]; i>=0; i = prev[i]){
		ret.emplace_back(a[i]);
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

void solve(){
	int n; cin >> n;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	vector<vector<int>>ans;
	int L = 0, R = n, K = n; 
	while (R>=L){
		int mid = (L+R)/2;
		if (mid*(mid-1) >= 2*n){
			K = mid;
			R = mid-1;
		} else L = mid+1;
	}

	function<void(vector<int>)> rec = [&](vector<int>a){
		//debug(a);
		if (a.empty()) return;
		vector<int>lis = Find(a);
		int n = (int)a.size();
		int L = 0, R = n, K = n; 
		while (R>=L){
			int mid = (L+R)/2;
			if (mid*(mid-1) >= 2*n){
				K = mid;
				R = mid-1;
			} else L = mid+1;
		}
		K--;
		int k = (int)lis.size();
		debug(a, K, k);
		if (k >= K){
			int ptr = 0;
			ans.emplace_back(lis);
			vector<int>b;
			for (int i = 0; i<(int)a.size(); i++){
				if (ptr < (int)lis.size() && a[i] == lis[ptr]){
					ptr++;
				} else {
					b.emplace_back(a[i]);
				}
			}
			rec(b);
		} else {
			reverse(a.begin(), a.end());
			while (a.size()){
				vector<int>lis = Find(a);
				reverse(lis.begin(), lis.end());
				ans.emplace_back(lis);
				reverse(lis.begin(), lis.end());
				int ptr = 0;
				vector<int>b;
				for (int i = 0; i<(int)a.size(); i++){
					if (ptr < (int)lis.size() && a[i] == lis[ptr]){
						ptr++;
					} else {
						b.emplace_back(a[i]);
					}
				}
				a = b;
			}
		}
	};

	rec(a);
	cout << (int)ans.size() << "\n";
	for (auto x: ans){
		cout << (int)x.size() << " ";
		for (auto y: x) cout << y << " ";
		cout << "\n";
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