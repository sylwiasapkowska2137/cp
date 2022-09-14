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

//https://cp-algorithms.com/string/prefix-function.html#final-algorithm
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}


void solve(){
	string s; cin >> s;
	int n = (int)s.size();
	vector<int>pi = prefix_function(s);
	pi.resize(pi.size()+20);
	int q; cin >> q;
	vector<pair<string, int>>tab;
	for (int i = 0; i < q; i++){
		string t; cin >> t;
		tab.emplace_back(t, i);
	}
	sort(tab.begin(), tab.end());
	vector<vector<int>>ans(q);
	for (int k = 0; k<q; k++){
		auto [t, idx] = tab[k];
		int last = n;
		if (k) {
			auto t2 = tab[k-1].first;
			for (int i = 0; i<min((int)t.size(), (int)t2.size()); i++){
				if (t[i] != t2[i]) break;
				last++;
			}
			while ((int)s.size() > last) s.pop_back();
			for (int i = last-n; i<(int)t.size(); i++) s += t[i];
		} else {
			s += t;
		}
		// debug(s, t);
		for (int i = last; i<(int)s.size(); i++){
			int j = pi[i-1];
			while (j > 0 && s[i] != s[j])
				j = pi[j-1];
			if (s[i] == s[j])
				j++;
			pi[i] = j;
		}
		for (int i = n; i<(int)s.size(); i++) ans[idx].emplace_back(pi[i]);
	}
	for (int i = 0; i<q; i++){
		for (auto x: ans[i]){
			cout << x << " ";
		}
		cout << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}