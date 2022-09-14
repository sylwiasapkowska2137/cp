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

map<pair<int, int>, int>mapa;

char query_first(int pos){
	pos++;
	cout << "? " << 1 << " " << pos << "\n";
	cout.flush();
	char c; cin >> c;
	return c;
}

int query_second(int l, int r){
	l++;r++;
	if (mapa.find({l, r}) != mapa.end()) return mapa[{l, r}];
	cout << "? " << 2 << ' ' << l << " " << r << "\n";
	cout.flush();
	int x; cin >> x;
	mapa[{l, r}] = x;
	return x;
}

void solve(){
	int n; cin >> n;
	string s;
	int p = 0;
	map<char, int>last;
	for (int i = 0; i<n; i++){
		int curr = (i ? query_second(0, i): 1);
		if (curr != p){
			s += query_first(i);
			last[s.back()] = i;
			p = curr;
			continue;
		}
		// debug(s);
		vector<int>pos;
		for (auto x: last) pos.emplace_back(x.second);
		sort(pos.begin(), pos.end());
		// debug(pos);
		int l = 0, r = (int)pos.size()-1, ans = pos[0];
		while (r>=l){
			int mid = (l+r)/2;
			vector<int>cnt(K);
			for (int k = pos[mid]; k<i; k++) cnt[s[k]-'a']++;
			int diff = 0;
			for (int ll = 0; ll<K; ll++) if (cnt[ll]) diff++;
			if (diff == query_second(pos[mid], i)){
				ans = pos[mid];
				l = mid+1;
			} else {
				r = mid-1;
			}
		}
		s += s[ans];
		last[s[ans]] = i;
		p = curr;
	}
	cout << "! " << s << "\n";
	cout.flush();
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}