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

LL ile(LL x){
	return x*(x+1)/2;
}

struct Event{
	LL ile;
	int val;
	Event() {}
	Event(LL _ile, int _val){
		ile = _ile, val = _val;
	}
};

void solve(){
	int n, h, k; cin >> n >> h >> k;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	a[0] = h+1;
	vector<int>maxi(n+1), mini(n+1);
	maxi.back() = a.back();
	vector<int>maxsuf, minsuf;
	for (int i = n-1; i>=0; i--){
		maxi[i] = max(maxi[i+1], a[i]);
		if (maxi[i]>maxi[i+1]) maxsuf.push_back(i+1);
	}
	a[0] = 0;
	mini.back() = a.back();
	for (int i = n-1; i>=0; i--){
		mini[i] = min(mini[i+1], a[i]);
		if (mini[i] < mini[i+1]) minsuf.push_back(i+1);
	}
	reverse(maxsuf.begin(), maxsuf.end());
	reverse(minsuf.begin(), minsuf.end());
	minsuf.push_back(n+1);
	maxsuf.push_back(n+1);
	debug(minsuf, maxsuf);
	vector<Event>tab;
	for (int i = 0; i<(int)minsuf.size()-1; i++){
		for (int j = 0; j<(int)maxsuf.size()-1; j++){
			//debug(minsuf[i], minsuf[i+1], maxsuf[j], maxsuf[j+1]);
			int l = max(minsuf[i], maxsuf[j]);
			int r = min(minsuf[i+1]-1, maxsuf[j+1]-1);
			debug(l, r);
			if (r < l) continue;
			debug(l, r, mini[l], maxi[l]);
			LL p = ile(r-l+1);
			tab.emplace_back(p, maxi[l]);
			tab.emplace_back(-p, mini[l]);
		}
	}
	sort (tab.begin(), tab.end(), [](auto A, auto B){return A.val > B.val;});
	for (auto [ile, val]:tab){
		debug(ile, val);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
